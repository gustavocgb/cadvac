#ifndef POSTS_H
#define POSTS_H

#include <string>
using namespace std;
class Posts
{
public:

    virtual void createPost(string name, string address, int vaccineCount=0)=0;
    virtual bool removePost(string name)=0;
    virtual Posts *getPost(string name)=0;
    virtual bool updatePost(Posts *pt, string name="", string address="", int vaccineCount=-1)=0;
    virtual bool updateVaccineNumber(Posts *pt, int vNumber)=0;
    virtual void listPosts()=0;
    virtual ~Posts(){}
    static Posts *generatePost();

    virtual string getPostName() const=0;
    virtual string getAddress() const=0;
    virtual int getVaccineCount() const=0;
    virtual int getId() const=0;
    virtual void setId(int value)=0;
    virtual void setPostName(const string &value)=0;
    virtual void setAddress(const string &value)=0;
    virtual void setVaccineCount(int value)=0;

};

#endif // POSTS_H
