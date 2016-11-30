/*
Static
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;
#include "../header/gun.h"

// The static keyword is used with member variables and functions.
// Static members are part of the class, not the object.
// That means that the one thing exists throughout your entire program.
// Any object of that class will have the same access to that one member.

// Sometimes people get confused because the word static means that something doesn't change, and expect static to work like const.
// While a static variables and functions can also be const, they don't have to be.
// They are not static in that they can't be changed, they are static in that they always exist. (can't be dynamically created or destroyed)


// The first way you can use the static keyword, is for a variable inside a function.
void countUp()
{
    static int counter; // By making this variable static, it will be the same one used in every function call.

    counter++;              // When the function is called, increment the counter and print out the number.
    cout << counter << endl;
}


int main()
{
    countUp();  // A small test of the countUp function using a static variable.
    countUp();  // This prints out 1, 2, 3, which means that the counter exists throughout the program.
    countUp();



    // Static members:

    cout << "Total Shots Fired: " << Gun::ShotsFired() << endl; // Static members are accessed with ::
                                                                // This static function is called before any object of the type even exists.

    {
        Gun gun = Gun(Magazine(6, 6));

        cout << "Total Shots Fired: " << gun.ShotsFired() << endl;  // It's also possible to access the function from an object of that type.
    }

    {
        Gun gunA = Gun(Magazine(2, 2));
        gunA.Fire(3);
        Gun gunB = Gun(Magazine(0, 6));
        gunB.Fire(3);

        cout << "Total Shots Fired: " << gunA.ShotsFired() << endl;  // Even though the function is called on two different objects, the value is the same between them.
        cout << "Total Shots Fired: " << gunA.ShotsFired() << endl;  // That's because the function doesn't care about the object at all.
    }




    cin.get();  // Wait for input before closing.
    return 0;   // End Program.
}