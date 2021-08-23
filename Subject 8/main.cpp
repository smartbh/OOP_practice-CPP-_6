#include <iostream>
#include <string>
using namespace std;

class product			
{
	int id;		// ID
	string product_detail;	//상품 설명
	string creator;		//생산자
	int price;		//가격
public:
	product() ;		//기본 생성자
	product(int id, string product_detail, string creator, int price);	//매개 변수 네개 생성자
	~product() { ; }	//기본 소멸자
	int setId();		//id 세팅
	string setProduct_detail();	//상품 설명 세팅
	string setCreator();		//생산자 세팅
	int setPrice();		//가격
	//void show();
	virtual void show() {}	//출력하는 함수
};

product::product(int id, string product_detail, string creator, int price) {
	this->id = id;
	this->product_detail = product_detail;
	this->creator = creator;
	this->price = price;
}

//void product::setId() {
//	cout << id;
//}
//
//void product::setProduct_detail() {
//	cout << product_detail;
//}
//
//void product::setCreator() {
//	cout << creator;
//}
//
//void product::setPrice() {
//	cout << price;
//}
//
//void product:: show() {
//	
//cout << "--- 상품ID : " << setId() << endl;
//cout << "상품설명 : " << setProduct_detail() << endl;
//cout << "생산자 : " << setCreator() << endl;
//cout << "가격 : " << setPrice() << endl;
//}

int product::setId()
{
	return id;
}

string product::setProduct_detail()
{
	return product_detail;
}

string product::setCreator()
{
	return creator;
}

int product::setPrice()
{
	return price;
}


class Book : public product			//책 클래스
{		
	int ISBN;		//isbn 번호
	string writer;		//저자
	string book_title;		//책 제목
public:
	Book() ;		//Book 클래스 기본 생성자
	~Book() { ; }		//Book 클래스 기본 소멸자
	Book(int id, string product_detail, string creator, int price, int isbn, string writer, string book_title); //매개변수 있는 클래스
	int setIsbn();		//isbn 세팅 함수
	string setWriter();	//저자 세팅
	string setBook_title();	//책 제목 세팅
	/*void Book_show();*/
	void show();		//출력함수
};

Book::Book(int id, string product_detail, string creator, int price, int isbn, string writer, string book_title) : product(id, product_detail, creator, price) {
	this->ISBN = isbn;
	this->writer = writer;
	this->book_title = book_title;

}

int Book::setIsbn()
{
	return ISBN;
}

string Book::setWriter()
{
	return writer;
}

string Book::setBook_title()
{
	return book_title;
}

void Book::show() {
	cout << "--- 상품ID : " << setId() << endl;
	cout << "상품설명 : " << setProduct_detail() << endl; 
	cout << "생산자 : " << setCreator() << endl; 
	cout << "가격 : " << setPrice() << endl; 
	cout << "ISBN : " << setIsbn() << endl; 
	cout << "책제목 : " << setBook_title() << endl; 
	cout << "저자 : " << setWriter() << endl;
}

class ConversationBook : public Book		//회화 책 클래스
{
	string language;		//언어
public:
	ConversationBook() ;	//기본 생성자
	~ConversationBook() { ; }	//기본 소멸자
	ConversationBook(int id, string product_detail, string creator, int price, int isbn, string writer
		, string book_title, string language);	//매개변수 있는 생성자
	string setLanguage();			//언어 세팅 함수
	/*void ConversationBook_show();*/
	void show();		//출력 함수
};

ConversationBook::ConversationBook(int id, string product_detail, string creator, int price, int isbn, 
									string writer, string book_title, string language) : Book(id, product_detail, creator, price, isbn, writer
										, book_title)
{
	this->language = language;
}

string ConversationBook::setLanguage() {
	return language;
}

void ConversationBook::show() {
	cout << "--- 상품ID : " << setId() << endl;
	cout << "상품설명 : " << setProduct_detail() << endl;
	cout << "생산자 : " << setCreator() << endl;
	cout << "가격 : " << setPrice() << endl;
	cout << "ISBN : " << setIsbn() << endl;
	cout << "책제목 : " << setBook_title() << endl;
	cout << "저자 : " << setWriter() << endl;
	cout << "언어 : " << setLanguage() << endl;

}

class CompactDisc : public product				//콤팩트 디스크 클래스
{
	string CD_title;		//앨범 제목
	string singer;			//가수 이름
public:
	CompactDisc() ;		//기본 생성자
	CompactDisc(int id, string product_detail, string creator, int price, string CD_title, string singer);		//매개변수 생성자
	~CompactDisc() { ; }	//기본 소멸자
	string setCdtitle();		//앨범 제목 세팅
	string setSinger();		//가수 세팅 함수
	/*void CompactDisc();*/
	void show();	//출력함수
};

CompactDisc::CompactDisc(int id, string product_detail, string creator, int price, string CD_title, string singer) :product(id, product_detail, creator, price) { 
	this->CD_title = CD_title;
	this->singer = singer;

}

string CompactDisc::setCdtitle() {
	return CD_title;
}

string CompactDisc::setSinger() {
	return singer;
}

void CompactDisc::show() {
	cout << "--- 상품ID : " << setId() << endl;
	cout << "상품설명 : " << setProduct_detail() << endl;
	cout << "생산자 : " << setCreator() << endl;
	cout << "가격 : " << setPrice() << endl;
	cout << "앨범제목 : " << setCdtitle() << endl;
	cout << "가수 : " << setSinger() << endl;
}

int main()
{
	product* p[100] = { 0 };		//상품 저장할 배열초기화
	int button;
	int id = 0;
	int productType;
	string product_detail, creator, writer, book_title, language, cd_title, singer;
	int price,ISBN;
	int i;

	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;

	while (true)
	{
		cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ?";
		cin >> button;

		if (button == 1)
		{
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ?";
			cin >> productType;

			while (getchar() != '\n');//버퍼 비우기

			if (productType == 1)		//상품 종류 책
			{
				cout << "상품설명>>";
				getline(cin, product_detail);	//상품설명
				cout << "생산자>>";
				getline(cin, creator);
				cout << "가격>>";
				cin >> price;
				while (getchar() != '\n');//버퍼 비우기
				cout << "책제목>>";
				getline(cin, book_title);
				cout << "저자>>";
				getline(cin, writer);
				cout << "ISBN>>";
				cin >> ISBN; 
				
				cout << endl;
				
				
				p[id] = new Book(id, product_detail, creator, price, ISBN, writer, book_title);
				id++;
				//Book(int id, string product_detail, string creator, int price, int isbn, string writer, string book_title)
			}

			else if (productType == 2)	  //상품 종류 음악cd
			{
				cout << "상품설명>>";
				getline(cin, product_detail);	//상품설명
				cout << "생산자>>";
				getline(cin, creator);
				cout << "가격>>";
				cin >> price;
				while (getchar() != '\n');//버퍼 비우기
				cout << "앨범제목>>";
				getline(cin, cd_title);
				cout << "가수>>";
				getline(cin, singer);
				cout << endl;

				p[id] = new CompactDisc(id, product_detail, creator, price, cd_title, singer);
				id++;
			}

			else if (productType == 3)	//상품종류 회화책
			{
				cout << "상품설명>>";
				getline(cin, product_detail);	//상품설명
				cout << "생산자>>";
				getline(cin, creator);
				cout << "가격>>";
				cin >> price;
				while (getchar() != '\n');//버퍼 비우기
				cout << "책제목>>";
				getline(cin, book_title);
				cout << "저자>>";
				getline(cin, writer);
				cout << "언어>>";
				getline(cin, language);
				cout << "ISBN>>";
				cin >> ISBN;
				cout << endl;


				p[id] = new ConversationBook(id, product_detail, creator, price, ISBN, writer, book_title, language);
				id++;
			}

			else
			{
				cout << "1~3번 을 입력해주세요" << endl;
				continue;
			}
		}
		else if (button == 2)
		{
			for (i = 0; i < id; i++)
			{
				p[i]->show();
				cout << endl;
			}
		}
		else if (button == 3)
		{
			cout << "프로그램을 종료 합니다";
			break;
		}
		else
		{
			cout << "1~3번 을 입력해주세요" << endl;
			continue;
		}

	}
}