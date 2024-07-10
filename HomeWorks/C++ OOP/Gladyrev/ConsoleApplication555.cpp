#include <iostream>

template<class Data> void List<Data>::Initialization()
{
    pHead = NULL;
    pTail = NULL;
}

template<class Data> void List<Data>::Deinitialization()
{
    while (pHead)
        RemoveBack();
    Initialization();
}

template<class Data> void List<Data>::RemoveBack()
{
    if (!pHead)
        return;
    Node<Data>* temp = pTail->Prev();
    delete pTail;
    pTail = temp;
    if (!pTail)
    {
        pHead = pTail;
        return;
    }
    pTail->Next(NULL);
}

template<class Data> void List<Data>::CopyProcedure(List& thisList, const List& list)
{
    Node<Data>* temp = list.pHead;
    while (temp)
    {
        thisList.InsertBack(temp->GetData());
        temp = temp->Next();
    }
}

template<class Data> List<Data>::List()
{
    Initialization();
}

template<class Data> List<Data>::List(const List& list)
{
    Initialization();
    CopyProcedure(*this, list);
}

template<class Data> List<Data>::~List()
{
    Deinitialization();
}

template<class Data> List<Data>& List<Data>::operator = (const List& list)
{
    Deinitialization();
    CopyProcedure(*this, list);
    return *this;
}

template<class Data> List<Data> List<Data>::operator + (const List<Data>& list)
{
    List<Data> temp;
    CopyProcedure(temp, *this);
    CopyProcedure(temp, list);
    return temp;
}