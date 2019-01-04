// Programmer:   Todd Herron
// Description:  Lab 6 Part B
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    double resistance;
    double voltage_across;
    double power_across;
};

vector <double> resistance_input(){
    vector <double> resistance_values;
    
    double resistance;
    
    for(int i=0; 0<1; ++i){
        cout << "Enter Resistance (0 to exit): ";
        cin >> resistance;
        
        if (resistance == 0){
            break;
        }
        else{
            resistance_values.push_back(resistance);
        }
    }
    
    return resistance_values;
}

double total_resistance(vector <double> resistance_values){
    int lng = resistance_values.size();
    double sum = 0;
    
    for (int i = 0; i < lng; ++i){
        sum = sum + resistance_values.at(i);
    }
    cout << "Total Resistance: " << sum << " ohm(s)" << endl;
    return sum;
}

double seriescurrent(double resistance, double voltage){
    double current = voltage/resistance;
    cout << "Series Current: " << current << " Amp(s)" << endl;
    return current;
}

double totalpower(double voltage, double current){
    double watts = voltage * current;
    cout << "Power: " << watts << " Watt(s)" << endl;
    return watts;
}

int main() {
    double voltage;
    cout << "Enter Voltage: ";
    cin >> voltage;
    
    vector <double> resistance_values = resistance_input();
    int lng = resistance_values.size();
    node N[lng];
    
    for (int i = 0; i < lng; ++i){
        N[i].resistance = resistance_values.at(i);
    }
    
    cout << endl;
    double resistance_sum = total_resistance(resistance_values);
    cout << "Input Voltage: " << voltage << " volt(s)" << endl;
    double current = seriescurrent(resistance_sum, voltage);
    double total_power = totalpower(voltage, current);
    
    cout << endl;
    
    for (int i = 0; i < lng; ++i){
        N[i].voltage_across = N[i].resistance * current;
    }
    
    for (int i = 0; i < lng; ++i){
        N[i].power_across = N[i].voltage_across * current;
    }
    
    for (int i = 0; i < lng; ++i){
        cout << "Node " << i << " Parameters:" << endl;
        cout << "Resistance: " << N[i].resistance << " ohm(s)" << endl;
        cout << "Voltage: " << N[i].voltage_across << " volt(s)" << endl;
        cout << "Power: " << N[i].power_across << " Watt(s)" << endl << endl;
    }
    
    
    
    return 0;
}