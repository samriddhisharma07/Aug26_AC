#include <iostream>
#include <memory>
using namespace std;
class Shader{
public:
    string name;
    string type;
    Shader(string n , string t) : name(n) , type(t){
    	cout<<"[Shader Compiled]"<<endl;
    }
    ~Shader(){
    	cout<<"[Shader Destroyed]"<<endl;
    }

    int getReferenceCount(shared_ptr<Shader> s){

    	return s.use_count();
    }
};
int main() {
	Shader s("vertex" , "fragment");
	auto shader = make_shared<Shader>("main_vert" , "vertex");
	cout << "Ref count: " << shader.use_count() << endl;

	{
	auto rendererRef = shader;
	cout << "Ref count: " << shader.use_count() << endl;

	auto editorRef   = shader;
	cout << "Ref count: " << shader.use_count() << endl;
	}
	cout << "Ref count: " << shader.use_count() << endl;
	return 0;
}
