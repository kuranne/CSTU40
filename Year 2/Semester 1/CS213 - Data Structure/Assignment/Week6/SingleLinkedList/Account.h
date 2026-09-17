#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <cstring>

class SLinkedList;

using namespace std;

class Account
{
private:
    string accID;
    string name;
    string surname;
    string username;
    SLinkedList *following;
    SLinkedList *followers;

public:
    Account(string, string, string, string);
    void addFollowing(Account *);
    // void addFollowers(Account *);
    void printFollowing();
    void printFollowers();
    void printFollowing(int m);
    void printFollowers(int m);
    Account *findMostFollowingInfluencer();
    Account *findMostFollowerInfluencer();
    Account *searchFollowerByUsername(string);
    Account *searchFollowingByUsername(string);
    void appendFollowing(SLinkedList *);
    void removeAllFollowing();
    void print();

    string getAccountID();
    string getName();
    string getUsername();
    string getSurname();
    SLinkedList *getFollowingList();
};

#endif // ACCOUNT_H_INCLUDED
