#include<iostream>
#include<string>
using namespace std;
class Alert{
    public:
        Alert(){warning=0;}
        void sendAlert(int code){
            warning=code;
            if(code==2)
                cout<<"Urgent!";
            else if (code==1)
                cout<<"HELP!";
        }
        bool wasAlertSend(){//Problem7_1
            if(warning==0)
                return false;
            return true;
        }
    private:
        int warning;
};
class Door{
    public:
        Door(){status.assign("CLOSE");}
        string getStatus(){return status;}
        void setStatus(string s){status.assign(s);}
    private:
        string status;
};

class IMonitor{
    public:
        virtual int execute(){};/*problem7-2*/
};

class Monitor:public IMonitor{
    public:
        Monitor(Door *d){
            door=d;
        }  
        int execute(){
            string s=door->getStatus();
            if(s.compare("BROKEN")==0)
                return 2;
            else if (s.compare("OPEN")==0)
                return 1/*problem7-3*/;
            else
                return 0;
        }
    private:
        Door *door;
};
class Server{
    private:
        IMonitor *doorMonitor /*problem7-4*/;
        Alert *alert;
    public:
        Server(Alert *a){
            alert =a;
        }
        void monitor(){
            int code=doorMonitor->execute();
            if(code>0)
                alert->sendAlert(code);/*problem7-5*/
        }
        void setMonitor(IMonitor *dm){
            doorMonitor=dm/*problem7-6*/;
        }
};
void testAlert(string msg){
    Door *door=new Door();
    Alert *alert =new Alert();
    IMonitor *monitor =new Monitor(door);
    Server *server=new Server(alert);
    server->setMonitor(monitor);
    door->setStatus(msg);
    server->monitor();
    if(!alert->wasAlertSend())
        cout << "OK!";
}
int main(){
    testAlert("OPEN");
    testAlert("CLOSE");
    testAlert("BROKEN");
    testAlert("HELP");
    return 0;
}

