#include "User.cpp"
#include "Group.cpp"


int main()
{
    Group *group = new Group();

    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);

    group->Subscribe(user1);
    group->Subscribe(user2);
    group->Subscribe(user3);

    group->notify("Hello All");
    group->notify("Good Morning!!");

    group->UnSubscribe(user1);
    group->notify("Good night");


    delete user1, user2, user3, group;
    return 0;
}