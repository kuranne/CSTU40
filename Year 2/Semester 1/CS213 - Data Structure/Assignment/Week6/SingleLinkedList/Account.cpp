#include "Account.h"
#include "SLinkedList.h"

Account::Account(string accID, string name, string surname, string username) : accID(accID), name(name), surname(surname), username(username)
{
    following = new SLinkedList();
    followers = new SLinkedList();
}

// add & rm methods

void Account::addFollowing(Account *acc)
{
    if (searchFollowingByUsername(acc->getUsername()) == nullptr)
    {
        following->addToTail(acc);
        acc->followers->addToTail(this);
    }
}

// searching methods

Account *searchByUsername(SLinkedList::Node *list, string *username)
{
    while (list != nullptr)
    {
        if (list->account->getUsername() == *username)
            return list->account;
        list = list->next;
    }

    return nullptr;
}

Account *Account::searchFollowingByUsername(string username)
{
    SLinkedList::Node *curr = this->following->head;
    return searchByUsername(curr, &username);
}

Account *Account::searchFollowerByUsername(string username)
{
    SLinkedList::Node *curr = this->followers->head;
    return searchByUsername(curr, &username);
}

// special methods

void Account::appendFollowing(SLinkedList *followings_list)
{
    SLinkedList::Node *curr = followings_list->head;
    while (curr != nullptr)
    {
        if (this->searchFollowingByUsername(curr->account->getUsername()) == nullptr)
        {
            this->addFollowing(curr->account);
        }
        curr = curr->next;
    }
}
