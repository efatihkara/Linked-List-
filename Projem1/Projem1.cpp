 #include<iostream>
#include<locale.h>

using namespace std;


struct MyStruct
{
	int age;
	int number;
	int tnumber;
	string name;
	string sname;

	MyStruct* Next;
};

MyStruct* Head = NULL;


int main()
{
	setlocale(LC_ALL, "Turkish");
	int secMenu = 0;


	while (secMenu != -1)
	{
		cout << "[" << " " << "Aşağıdaki seçeneklerden hangisini Yapmak İstersiniz ?" << " " << "]" << endl;
		cout << "[" << "Öğrenci Eklemek İçin 1'e Basınız. " << "]" << endl;
		cout << "[" << "Öğrenci Silmek İçin 2'e Basınız. " << "]" << endl;
		cout << "[" << "Öğrenci Listelemek İçin 3'e Basınız. " << "]" << endl;
		cout << "[" << "Öğrenci Bulmak İçin 4'e Basınız. " << "]" << endl;
		cout << "[" << "Çıkış İçin 5'e Basınız. " << "]" << endl;
		cin >> secMenu;
		switch (secMenu)
		{
		case 1://Veri Ekleme
		{
			MyStruct* tmpMystruct = new MyStruct();
			cout << "No giriniz: ";
			cin >> tmpMystruct->number;
			cout << endl;
			cout << "Ad giriniz: ";
			cin >> tmpMystruct->name;
			cout << endl;
			cout << "Soyad giriniz: ";
			cin >> tmpMystruct->sname;
			cout << endl;
			cout << "Yas giriniz: ";
			cin >> tmpMystruct->age;
			cout << endl;
			cout << "T.C No giriniz: ";
			cin >> tmpMystruct->tnumber;
			//buradaki verileri taşımayı tamamen tmpMystruct üzerinden tutarak götürüyoruz


			if (Head == NULL)//eğer listenin başında ise verileri oraya salladık
			{
				Head = tmpMystruct;
			}

			else//değilse Next Komutu ile bağlantıladık bağlantıladıktan sonra Başa Dönderdik
			{
				tmpMystruct->Next = Head;
				Head = tmpMystruct;
			}
		}
		break;
		case 2:// Veri Silme 
		{
			bool searc;
			if (Head == NULL)//Liste Boş ise 
			{
				cout << "[*********" << "Listede Herhangi bir öğrenci bulunmamaktadır" << "*********]" << endl;

			}
			else
			{
				MyStruct* SilNode = Head;
				MyStruct* OncekiNode = NULL;
				int No;
				cout << "Silmek istediginiz Ogrenci Numarasını giriniz.";
				cin >> No;
				cout << endl;
				while (SilNode != NULL)//null olana kadar çalışacaktır 
				{
					if (SilNode->number == No)//girilen Numara ile eşleştirme 
					{
						searc = true;
						if (SilNode == Head)//eğer Nodemiz Başta ise
						{
							Head = SilNode->Next;//kuyruk yapıyoruz
							delete SilNode;
							SilNode = Head;
						}
						else
						{
							OncekiNode->Next = SilNode->Next;
							delete SilNode;
							SilNode = OncekiNode->Next;
							break;
						}

					}
					else
					{
						OncekiNode = SilNode;
						SilNode = SilNode->Next;
					}

				}
			}
			if (searc == false)
				cout << "Silinecek Ogrenci bulunamadı" << endl;

			
		}
		break;

		case 3://Listelemek İçin
		{
			
			if (Head == NULL)
			{
				cout << "[*********" << "Listede Herhangi bir öğrenci bulunmamaktadır" << "*********]" << endl;

			}
			else
			{
				MyStruct* Node = Head;//her case altında yapılmasının sebebi Struct içerisindeki verilerimize erişebilmek için 
				cout << "No\t" << "Ad\t" << "Soyad\t" << "Yas\t" << "T.C NO" << endl;
				while (Node != NULL)
				{
					cout << Node->number << "\t" << Node->name << "\t" << Node->sname << "\t" << Node->age << "\t" << Node->tnumber << endl;
					Node = Node->Next;//verilerimizi listelerken diğer veri beleğine geçerek bize kuyruk işlemini gerçekleştiriyor.
				}
			}
		}
		break;
		case 4://Bulmak İçin
		{
			bool searchh = false;
			if (Head==NULL)
			{
				cout << "[*********" << "Listede Herhangi bir öğrenci bulunmamaktadır" << "*********]" << endl;
			}
			else
			{
				MyStruct* IlkNode = Head;//Listenin başından sonuna kadar kuyruk yaparak arama yapma için başa heade eşitledi ve sonrasında while içerisine girerse eğer bulana kadar aşağıda kuyruk yaptık
				int no;
				cout << "Aranan Öğrencinin Numarasını Giriniz: " << endl;
				cin >> no;
				while (IlkNode!=NULL)
				{
					if (IlkNode->number==no)
					{
						cout << "Ogrenci bulundu. Ad / Soyad " << IlkNode->name << "/" << IlkNode->sname << endl;
						searchh = true;
						break;
					}
					IlkNode = IlkNode->Next;//kuyruk mantığını burada bir sonraki sıraya ekleyerek gidiyoruz :)

				}
				
			}
			if (searchh == false)//burada zaten search false olarak geleceği için içeride arama yaptıktanm sonra bulamazsa aranan öğrenci eşlezmese direk false olarak ilk başta aldığımızdan direk bizi buraya atacaktır.
				cout << "Ogrenci bulunamadı" << endl;

		}
		break;
		case 5://programdan çıkış yapmak için 
		{
			cout << "Programdan cikiliyor" << endl;
			secMenu = -1;
			exit;
		}
		break;
		}
	}

}


