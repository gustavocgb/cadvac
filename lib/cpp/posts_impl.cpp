#include "./lib/hpp/posts_impl.h"

Posts_Impl::Posts_Impl()
{
    setId(0);
    setPostName("");
    setAddress("");
    setVaccineCount(0);
}

Posts_Impl::Posts_Impl(string name, string address, int vaccineCount)
{
    setPostName(name);
    setAddress(address);
    setVaccineCount(vaccineCount);
}

Posts_Impl::~Posts_Impl()
{

}

void Posts_Impl::createPost(string name, string address, int vaccineCount)
{
    Posts *p = new Posts_Impl(name, address, vaccineCount);
    posts.push_back(p);
}

bool Posts_Impl::removePost(string name)
{
    for(auto i: posts){

        if(i->getPostName() == name){
            posts.remove(i);
            return true;
        }
    }
    return false;
}

Posts *Posts_Impl::getPost(string name)
{
    for(auto it: posts){
        if(it->getPostName() == name){
            return it;
        }
    }
    return nullptr;
}

bool Posts_Impl::updatePost(Posts *pt, string name, string address, int vaccineCount)
{
    for(auto i: posts){
        if(i == pt){
            i->setPostName(name);
            i->setAddress(address);
            i->setVaccineCount(vaccineCount);
            return true;
        }
    }
    return false;
}

bool Posts_Impl::updateVaccineNumber(Posts *pt, int vNumber)
{
    for(auto i: posts){
        if(i == pt){
            i->setVaccineCount(vNumber);
            return true;
        }
    }
    return false;
}

void Posts_Impl::listPosts()
{

    for(auto it : posts){
        cout<<it->getPostName()<<", "<<it->getAddress()<<endl;
    }
}

string Posts_Impl::getPostName() const
{
    return postName;
}

void Posts_Impl::setPostName(const string &value)
{
    postName = value;
}

string Posts_Impl::getAddress() const
{
    return address;
}

void Posts_Impl::setAddress(const string &value)
{
    address = value;
}

int Posts_Impl::getVaccineCount() const
{
    return vaccineCount;
}
int Posts_Impl::getId()const{
    return id;
}
void Posts_Impl::setId(int value){
    id = value;
}


list<Posts*> Posts_Impl::posts;
Posts *Posts::generatePost(){
    return Posts_Impl::generatePost();
}
Posts *Posts_Impl::generatePost()
{
    Posts* post = new Posts_Impl();
    return post;
}

void Posts_Impl::setVaccineCount(int value)
{
    vaccineCount = value;
}

Posts_Impl &Posts_Impl::operator=(Posts_Impl &copy)
{
    if(&copy == this) return (*this);

    this->postName = copy.postName;
    this->address = copy.address;
    this->vaccineCount = copy.vaccineCount;
    this->posts = copy.posts;

    return (*this);
}
ostream &operator<<(ostream &out, const Posts_Impl &p)
{
    out<<p.getPostName()<<", "<<p.getAddress()<<", "<<p.getVaccineCount()<<endl;
    return out;
}
