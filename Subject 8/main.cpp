#include <iostream>
#include <string>
using namespace std;

class product			
{
	int id;		// ID
	string product_detail;	//��ǰ ����
	string creator;		//������
	int price;		//����
public:
	product() ;		//�⺻ ������
	product(int id, string product_detail, string creator, int price);	//�Ű� ���� �װ� ������
	~product() { ; }	//�⺻ �Ҹ���
	int setId();		//id ����
	string setProduct_detail();	//��ǰ ���� ����
	string setCreator();		//������ ����
	int setPrice();		//����
	//void show();
	virtual void show() {}	//����ϴ� �Լ�
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
//cout << "--- ��ǰID : " << setId() << endl;
//cout << "��ǰ���� : " << setProduct_detail() << endl;
//cout << "������ : " << setCreator() << endl;
//cout << "���� : " << setPrice() << endl;
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


class Book : public product			//å Ŭ����
{		
	int ISBN;		//isbn ��ȣ
	string writer;		//����
	string book_title;		//å ����
public:
	Book() ;		//Book Ŭ���� �⺻ ������
	~Book() { ; }		//Book Ŭ���� �⺻ �Ҹ���
	Book(int id, string product_detail, string creator, int price, int isbn, string writer, string book_title); //�Ű����� �ִ� Ŭ����
	int setIsbn();		//isbn ���� �Լ�
	string setWriter();	//���� ����
	string setBook_title();	//å ���� ����
	/*void Book_show();*/
	void show();		//����Լ�
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
	cout << "--- ��ǰID : " << setId() << endl;
	cout << "��ǰ���� : " << setProduct_detail() << endl; 
	cout << "������ : " << setCreator() << endl; 
	cout << "���� : " << setPrice() << endl; 
	cout << "ISBN : " << setIsbn() << endl; 
	cout << "å���� : " << setBook_title() << endl; 
	cout << "���� : " << setWriter() << endl;
}

class ConversationBook : public Book		//ȸȭ å Ŭ����
{
	string language;		//���
public:
	ConversationBook() ;	//�⺻ ������
	~ConversationBook() { ; }	//�⺻ �Ҹ���
	ConversationBook(int id, string product_detail, string creator, int price, int isbn, string writer
		, string book_title, string language);	//�Ű����� �ִ� ������
	string setLanguage();			//��� ���� �Լ�
	/*void ConversationBook_show();*/
	void show();		//��� �Լ�
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
	cout << "--- ��ǰID : " << setId() << endl;
	cout << "��ǰ���� : " << setProduct_detail() << endl;
	cout << "������ : " << setCreator() << endl;
	cout << "���� : " << setPrice() << endl;
	cout << "ISBN : " << setIsbn() << endl;
	cout << "å���� : " << setBook_title() << endl;
	cout << "���� : " << setWriter() << endl;
	cout << "��� : " << setLanguage() << endl;

}

class CompactDisc : public product				//����Ʈ ��ũ Ŭ����
{
	string CD_title;		//�ٹ� ����
	string singer;			//���� �̸�
public:
	CompactDisc() ;		//�⺻ ������
	CompactDisc(int id, string product_detail, string creator, int price, string CD_title, string singer);		//�Ű����� ������
	~CompactDisc() { ; }	//�⺻ �Ҹ���
	string setCdtitle();		//�ٹ� ���� ����
	string setSinger();		//���� ���� �Լ�
	/*void CompactDisc();*/
	void show();	//����Լ�
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
	cout << "--- ��ǰID : " << setId() << endl;
	cout << "��ǰ���� : " << setProduct_detail() << endl;
	cout << "������ : " << setCreator() << endl;
	cout << "���� : " << setPrice() << endl;
	cout << "�ٹ����� : " << setCdtitle() << endl;
	cout << "���� : " << setSinger() << endl;
}

int main()
{
	product* p[100] = { 0 };		//��ǰ ������ �迭�ʱ�ȭ
	int button;
	int id = 0;
	int productType;
	string product_detail, creator, writer, book_title, language, cd_title, singer;
	int price,ISBN;
	int i;

	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;

	while (true)
	{
		cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ?";
		cin >> button;

		if (button == 1)
		{
			cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ?";
			cin >> productType;

			while (getchar() != '\n');//���� ����

			if (productType == 1)		//��ǰ ���� å
			{
				cout << "��ǰ����>>";
				getline(cin, product_detail);	//��ǰ����
				cout << "������>>";
				getline(cin, creator);
				cout << "����>>";
				cin >> price;
				while (getchar() != '\n');//���� ����
				cout << "å����>>";
				getline(cin, book_title);
				cout << "����>>";
				getline(cin, writer);
				cout << "ISBN>>";
				cin >> ISBN; 
				
				cout << endl;
				
				
				p[id] = new Book(id, product_detail, creator, price, ISBN, writer, book_title);
				id++;
				//Book(int id, string product_detail, string creator, int price, int isbn, string writer, string book_title)
			}

			else if (productType == 2)	  //��ǰ ���� ����cd
			{
				cout << "��ǰ����>>";
				getline(cin, product_detail);	//��ǰ����
				cout << "������>>";
				getline(cin, creator);
				cout << "����>>";
				cin >> price;
				while (getchar() != '\n');//���� ����
				cout << "�ٹ�����>>";
				getline(cin, cd_title);
				cout << "����>>";
				getline(cin, singer);
				cout << endl;

				p[id] = new CompactDisc(id, product_detail, creator, price, cd_title, singer);
				id++;
			}

			else if (productType == 3)	//��ǰ���� ȸȭå
			{
				cout << "��ǰ����>>";
				getline(cin, product_detail);	//��ǰ����
				cout << "������>>";
				getline(cin, creator);
				cout << "����>>";
				cin >> price;
				while (getchar() != '\n');//���� ����
				cout << "å����>>";
				getline(cin, book_title);
				cout << "����>>";
				getline(cin, writer);
				cout << "���>>";
				getline(cin, language);
				cout << "ISBN>>";
				cin >> ISBN;
				cout << endl;


				p[id] = new ConversationBook(id, product_detail, creator, price, ISBN, writer, book_title, language);
				id++;
			}

			else
			{
				cout << "1~3�� �� �Է����ּ���" << endl;
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
			cout << "���α׷��� ���� �մϴ�";
			break;
		}
		else
		{
			cout << "1~3�� �� �Է����ּ���" << endl;
			continue;
		}

	}
}