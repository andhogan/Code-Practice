#include <iostream>
#include <string>

using namespace std;

class Tesla{
public:
    Tesla(){
        drivetrain = "NOT ASSIGHNED";
        body_shape = "EMPTY";
        wiring_type = 0;
        interior_type = "NOT ASSEMBLED";
        body_color = "NO COLOR";
        serial_number = 0;
    }

    string drivetrain;
    string body_shape;
    string interior_type;
    string body_color;

    void set_serialnumber(int password, int serialnum){
        if(password == 123){
            serial_number = serialnum;
        } else {
            cout << "wrong password" << endl;
        }
    }

    int get_serialnumber(int password){
        if(password == 123){
            return serial_number;
        } else {
            cout << "wrong password" << endl;
        }
        return -1;
    }
    
private:
    int serial_number;
    int wiring_type;

};

int main(){

    Tesla model3;

    model3.body_color = "green";
    model3.body_shape = "extra-curved";
    model3.drivetrain = "AWD";
    model3.interior_type = "leather";
    model3.set_serialnumber(123, 2);
    model3.set_serialnumber(321, 5);

    cout << "my model3 is " << model3.body_color << " and has " << model3.interior_type << " seats. " << endl;
    cout << "serial is " << model3.get_serialnumber(123) << endl;

    return 0;
}