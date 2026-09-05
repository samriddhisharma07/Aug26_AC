#include <iostream>
#include <memory>
using namespace std;
class Texture{
public:
    string name; int width; int height;
    Texture(){
        cout<<"[Texture loaded]"<<endl;
    }
    Texture(string n , int w , int h) : name(n) , width(w) , height(h){
        cout<<"[Texture loaded]"<<endl;
    }
    ~Texture(){
        cout<<"[Texture released]"<<endl;
    }
    void display()const{
        cout<<name<<endl;
        cout<<width<<endl;
        cout<<height<<endl;
    }
};
int main(){
    Texture t;
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);
    tex1->display();
    //unique_ptr<Texture>tex2 = tex1;   // Error: unique_ptr cannot be copied.
                                        // It has exclusive ownership of the object.
                                        // Use std::move() to transfer ownership instead.
    unique_ptr<Texture>tex2 = std::move(tex1);
    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;

}