#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Input variables
    double Ep, I0, Pi, Isc, Esc, Psc, Sfl, k, powerFactor, Pcufl;

    // Ask the user which test they want
    cout << "Choose the type of test:\n";
    cout << "1. Open Circuit Test\n";
    cout << "2. Short Circuit Test\n";
    cout << "3. Efficiency Test\n";

    int testChoice;
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> testChoice;

    // Perform calculations based on the chosen test
    switch (testChoice) {
        case 1: {
            // Open Circuit Test
            // Additional inputs: Exciting current (I0), Iron loss (Pi)
            cout << "Enter the voltage of the primary coil (Ep): ";
            cin >> Ep;

            cout << "Enter the exciting current (I0): ";
            cin >> I0;
            cout << "Enter the iron loss (Pi): ";
            cin >> Pi;

            // Perform calculations for open circuit test
            double Sm = I0 * Ep;
            double Qm = sqrt(pow(Sm, 2) - pow(Pi, 2));
            double Rm = (pow(Ep, 2) / Pi);
            double Xm = (pow(Ep, 2) / Qm);

            // Display results
            cout << "Results for Open Circuit Test:\n";
            cout << "Magnetizing Current (Sm): " << Sm << endl;
            cout << "Reactive Power (Qm): " << Qm << endl;
            cout << "Magnetizing Resistance (Rm): " << Rm << endl;
            cout << "Magnetizing Reactance (Xm): " << Xm << endl;

            break;
        }

        case 2: {
            // Short Circuit Test
            // Additional inputs: Short circuit current (Isc), Short circuit voltage (Esc), Short circuit power (Psc)
            cout << "Enter the voltage of the primary coil (Ep): ";
            cin >> Ep;

            cout << "Enter the short circuit current (Isc): ";
            cin >> Isc;
            cout << "Enter the short circuit voltage (Esc): ";
            cin >> Esc;
            cout << "Enter the short circuit power (Psc): ";
            cin >> Psc;

            // Perform calculations for short circuit test
            double Zp = Esc / Isc;
            double Rp = Psc / pow(Isc, 2);
            double Xp = sqrt(pow(Zp, 2) - pow(Rp, 2));

            // Display results
            cout << "Results for Short Circuit Test:\n";
            cout << "Primary Impedance (Zp): " << Zp << endl;
            cout << "Primary Resistance (Rp): " << Rp << endl;
            cout << "Primary Reactance (Xp): " << Xp << endl;

            break;
        }

        case 3: {
            // Efficiency Test
            // Additional inputs: Full load apparent power (Sfl), Voltage regulation factor (k), Power factor, Full load copper loss (Pcufl), Iron loss (Pi)
            cout << "Enter the full load apparent power (Sfl): ";
            cin >> Sfl;
            cout << "Enter the voltage regulation factor (k): ";
            cin >> k;
            cout << "Enter the power factor: ";
            cin >> powerFactor;
            cout << "Enter the full load copper loss (Pcufl): ";
            cin >> Pcufl;
            cout << "Enter the iron loss (Pi): ";
            cin >> Pi;

            // Perform calculations for efficiency test
            double Po = Sfl * k * powerFactor;
            double Pcu = pow(k, 2) * Pcufl;
            double efficiency = Po / (Po + Pi + Pcu);

            // Display results
            cout << "Results for Efficiency Test:\n";
            cout << "Output Power (Po): " << Po << endl;
            cout << "Copper Loss (Pcu): " << Pcu << endl;
            cout << "Efficiency: " << efficiency * 100 << "%\n";  // Displaying efficiency as a percentage

            break;
        }

        default:
            cout << "Invalid choice. Exiting program.\n";
            return 1;
    }

    return 0;
}
