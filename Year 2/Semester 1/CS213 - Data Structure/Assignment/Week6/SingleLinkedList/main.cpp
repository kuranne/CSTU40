#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
    Account *a1 = new Account("5209610111", "Bingjiao", "He", "binggang");
    Account *a2 = new Account("5209680123", "Chaiwichit", "Boonsaner", "ohm123");
    Account *a3 = new Account("5509644444", "Mike", "Piromporn", "mike19");
    Account *a4 = new Account("6209601456", "Tai", "Orathai", "tai789");
    Account *a5 = new Account("6209650112", "Tzuying", "Tai", "tai19");
    Account *a6 = new Account("6309610124", "Lalisa", "M.", "lalalalisa_m");
    Account *a7 = new Account("6309621111", "Ratchanok", "Intanon", "may4432");
    Account *a8 = new Account("5907450123", "Busanan", "Ongbamrungphan", "cream123");
    Account *a9 = new Account("6104010001", "Xuerui", "Li", "lxr1991");
    Account *a10 = new Account("6104010002", "Chongwei", "Li", "lcw1987");

    a1->addFollowing(a5);
    a1->addFollowing(a7);
    a1->addFollowing(a8);
    a1->addFollowing(a9);

    a5->addFollowing(a1);
    a5->addFollowing(a7);
    a5->addFollowing(a8);
    a5->addFollowing(a9);
    a5->addFollowing(a3);
    a5->addFollowing(a6);

    a2->addFollowing(a1);
    a2->addFollowing(a7);
    a2->addFollowing(a8);
    a2->addFollowing(a9);
    a2->addFollowing(a3);
    a2->addFollowing(a6);

    a3->addFollowing(a1);
    a3->addFollowing(a7);
    a3->addFollowing(a8);
    a3->addFollowing(a9);
    a3->addFollowing(a6);
    a3->addFollowing(a6);

    a4->addFollowing(a1);

    a8->addFollowing(a6);

    a8->printFollowing();
    a8->printFollowers();

    a8->printFollowing(2);
    a8->printFollowers(2);

    if (a8->findMostFollowingInfluencer())
        cout << "The influencer among people following " << a8->getName()
             << " is " << a8->findMostFollowingInfluencer()->getName() << endl;
    else
        cout << "There's no influencer among people following " << a8->getName() << endl;

    if (a8->findMostFollowerInfluencer())
        cout << "The influencer among people followed by " << a8->getName()
             << " is " << a8->findMostFollowerInfluencer()->getName() << endl;
    else
        cout << "There's no influencer among people followed by " << a8->getName() << endl;

    if (a10->findMostFollowerInfluencer())
        cout << "The influencer among people followed by " << a10->getName() << " is " << a10->findMostFollowerInfluencer()->getName() << endl;
    else
        cout << "There's no influencer among people followed by " << a10->getName() << endl;

    if (a8->searchFollowerByUsername("mike19"))
        cout << a8->getName() << " has " << a8->searchFollowerByUsername("mike19")->getName()
             << "as his/her follower." << endl;
    else
        cout << "Username not found in the follower list." << endl;

    if (a8->searchFollowerByUsername("mike1911"))
        cout << a8->getName() << " has " << a8->searchFollowerByUsername("mike19")->getName()
             << "as his/her follower." << endl;
    else
        cout << "Username not found in the follower list." << endl;

    if (a6->searchFollowingByUsername("binggang"))
        cout << a6->getName() << " has " << a6->searchFollowerByUsername("binggang")->getName()
             << "as his/her follower." << endl;
    else
        cout << "Username not found in the following list." << endl;

    if (a5->searchFollowingByUsername("may4432"))
        cout << a5->getName() << " has " << a5->searchFollowingByUsername("may4432")->getName()
             << " as his/her follower." << endl;
    else
        cout << "Username not found in the following list." << endl;

    a4->printFollowing();
    a4->appendFollowing(a3->getFollowingList());
    a4->printFollowing();

    a4->removeAllFollowing();

    a4->printFollowing();
    return 0;
}
