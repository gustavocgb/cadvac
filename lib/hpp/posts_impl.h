#ifndef POSTS_IMPL_H
#define POSTS_IMPL_H
#include <string>
#include "posts.h"
#include <iostream>
#include <list>
using namespace std;

class Posts_Impl : public Posts
{
public:
    Posts_Impl();
    Posts_Impl(string name, string address, int vaccineCount=0);
    virtual ~Posts_Impl();

    void createPost(string name, string address, int vaccineCount=0);
    bool removePost(string name);
    Posts *getPost(string name);
    bool updatePost(Posts *pt, string name="", string address="", int vaccineCount=-1);
    bool updateVaccineNumber(Posts *pt, int vNumber);
    void listPosts();

    string getPostName() const;
    string getAddress() const;
    int getVaccineCount() const;
    int getId() const;

    static Posts *generatePost();
    Posts_Impl &operator=(Posts_Impl&);
    friend ostream &operator<<(ostream &out, const Posts_Impl &p);

protected:
    int id;
    string postName;
    string address;
    int vaccineCount;
    static list<Posts*> posts;
    void setPostName(const string &value);
    void setAddress(const string &value);
    void setVaccineCount(int value);
    void setId(int value);
};

#endif // POSTS_H
