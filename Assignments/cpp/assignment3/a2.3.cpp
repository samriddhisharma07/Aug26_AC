#include <iostream>
#include <memory>
using namespace std;
class AudioClip{
	string name;
	double version;
public:
	AudioClip(string n , double v):name(n),version(v){

	}
	string getName(){
		return name;
	}
//	void checkStatus(weak_ptr<AudioClip>observer ){
//		if (observer .lock() != nullptr)
//		    cout << "alive";
//		else
//		    cout << "dead";
//	}
};
int main() {
	AudioClip ac("explosion" , 3.5);
	auto audio = make_shared<AudioClip>("explosion" , 3.5);
	weak_ptr <AudioClip> observer  = audio;
	//ac.checkStatus(observer );
	if(auto clip = observer .lock() ){
		cout << "Clip alive: " << clip->getName() << endl;
	}
	audio.reset();
	if (observer .expired())
	cout << "Clip already unloaded." << endl;
	//audio.reset();
	return 0;
}