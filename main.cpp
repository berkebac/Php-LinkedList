#include <iostream>

using namespace std;
template <class T>
class Node{
  public:
    T sayi_1, sayi_2;
    Node *sonraki;

    Node<T>(void);
    Node<T>( T s1, T s2);
    Node<T>* operator+( Node<T> &b);
};
template <class T>
Node<T>::Node(void){
    sayi_1=0;
    sayi_2=0;
    sonraki=0;
}
template <class T>
Node<T>::Node(T s1, T s2){
    sayi_1=s1;
    sayi_2=s2;
    sonraki=0;
}
template <class T>
Node<T>* Node<T>::operator+( Node<T> &b){
    Node<T> *c = new Node<T>;
    c->sayi_1 = this->sayi_1 + b.sayi_1;
    c->sayi_2 = this->sayi_2 + b.sayi_2;
    return c;
}

typedef double Node_Value_Type;

class LinkedList{
public:
    Node<Node_Value_Type> *header;
    LinkedList(void);
    void ListeninBasindakiElemaniSil(void);
    void ListeninSonundakiElemaniSil(void);
    void ListeyeElemanEkle( Node<Node_Value_Type> *yeni);
    void ListeyeElemanEkle(Node_Value_Type s1, Node_Value_Type s2);
    void ListeninArasinaElemanEkle( Node<Node_Value_Type> *yeni, int siraNumarasi);
    void ListeninArasinaElemanEkle( Node_Value_Type s1, Node_Value_Type s2, int siraNumarasi);
    void ListeninArasindakiElemaniSil( int siraNumarasi );
    void ListeyiYazdir(void);

};
LinkedList::LinkedList(void){
    header=0;
}

void LinkedList::ListeninArasindakiElemaniSil(int siraNumarasi){
    if( header==0 ){
        cout<<"Listede silinecek eleman bulunamamıştır. Liste boştur."<<endl;
        return;
    }
    if( siraNumarasi==0 ){
        ListeninBasindakiElemaniSil();
        return;
    }

    Node<Node_Value_Type> *temp=header;
    int i=0;

    while( i<siraNumarasi-1 ){
        temp = temp->sonraki;
        if( temp->sonraki == 0){
            cout<<"Silinmek istenen eleman listede bulunmamaktadır"<<endl;
            return;
        }
        i++;
    }
    Node<Node_Value_Type> *temp2 = temp->sonraki;
    Node<Node_Value_Type> *yedek = temp2->sonraki;
    delete temp2;
    temp->sonraki = yedek;


}

void LinkedList::ListeninArasinaElemanEkle(Node_Value_Type s1, Node_Value_Type s2, int siraNumarasi){
    Node<Node_Value_Type> *yeni = new Node<Node_Value_Type>(s1,s2);
    ListeninArasinaElemanEkle( yeni, siraNumarasi);
}
void LinkedList::ListeninArasinaElemanEkle(Node<Node_Value_Type> *yeni, int siraNumarasi){
    if( header==0 ){
        ListeyeElemanEkle( yeni );
        return;
    }

    if( siraNumarasi==0 ){
        yeni->sonraki = header;
        header = yeni;
        return;
    }

    Node<Node_Value_Type> *temp = header;
    int i=0;
    while( i<siraNumarasi-1 ){
        temp = temp->sonraki;
        if( temp->sonraki == 0){
            ListeyeElemanEkle( yeni );
            return;
        }
        i++;
    }

    Node<Node_Value_Type> *temp2 = temp->sonraki;
    temp->sonraki = yeni;
    yeni->sonraki = temp2;


}

void LinkedList::ListeyiYazdir(void){
    if( header == 0 ){
        cout<<"Listede eleman bulunmamaktadır."<<endl;
        return;
    }
    cout<<"-----"<<endl;
    Node<Node_Value_Type> *temp=header;
    while( temp!= 0 ){
        cout<<temp->sayi_1<<" "<<temp->sayi_2<<endl;
        temp=temp->sonraki;
    }
    cout<<"------------"<<endl;
}

void LinkedList::ListeyeElemanEkle(Node<Node_Value_Type> *yeni){
    if( header==0 ){
        header=yeni;
    }else{
        Node<Node_Value_Type> *temp=header;
        while( temp->sonraki != 0 )
            temp=temp->sonraki;

        temp->sonraki = yeni;
    }
}
void LinkedList::ListeyeElemanEkle(Node_Value_Type s1, Node_Value_Type s2){
    if( header==0 ){
        header=new Node<Node_Value_Type>(s1,s2);
    }else{
        Node<Node_Value_Type> *temp=header;
        while( temp->sonraki != 0 )
            temp=temp->sonraki;

        temp->sonraki = new Node<Node_Value_Type>(s1,s2);
    }
}
void LinkedList::ListeninSonundakiElemaniSil(void){
    if( header == 0 ){
        cout<<"Listede eleman bulunmamaktadır."<<endl;
        return;
    }
    if( header->sonraki == 0 ){
        delete header;
        header = 0;
        return;
    }

    Node<Node_Value_Type> *temp=header;
    while( temp->sonraki->sonraki != 0 )
        temp=temp->sonraki;

    Node<Node_Value_Type> *temp2 = temp->sonraki;
    delete temp2;
    temp->sonraki = 0;


}

void LinkedList::ListeninBasindakiElemaniSil(void){
    if( header == 0 ){
        cout<<"Listede eleman bulunmamaktadır."<<endl;
        return;
    }

    Node<Node_Value_Type> *temp=header;
    header = header->sonraki;
    delete temp;

}


int main()
{
    Node<Node_Value_Type> *n1 = new Node<Node_Value_Type>(13.4,56.3);

    Node<Node_Value_Type> *n2 = new Node<Node_Value_Type>(65.1,34.9);

    Node<Node_Value_Type> *n3;

    n3 = *n1 + *n2;

    LinkedList * listem = new LinkedList;


    listem->ListeyeElemanEkle(n3);

    listem->ListeyeElemanEkle(10.2,35.6);

    listem->ListeyeElemanEkle(n1);
    listem->ListeyeElemanEkle(36.2,78.1);
    listem->ListeyeElemanEkle(37.1,78);
    listem->ListeyeElemanEkle(38.5,78);
    listem->ListeyeElemanEkle(39.7,78);
    listem->ListeyeElemanEkle(40.6,78);
    listem->ListeyeElemanEkle(n2);

    listem->ListeyiYazdir();

    listem->ListeninArasindakiElemaniSil( 8 );

    listem->ListeyiYazdir();

    return 0;
}







