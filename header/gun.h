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

#pragma once        // Prevents the compiler from reading this file twice.

// Holds bullet information for the gun class.
struct Magazine
{
    // member variables
    int bullets;
    const int capacity;     // capacity is const, must be given a value in the constructor.

    // This is a constructor declaration.
    Magazine(int bulletsinitial, int bulletsCapacity);
};

// This is a class declaration.
// A class is a type of object.
class Gun
{
    Magazine mag;
    static int shotsFired;  // Static member variable declaration.
    // Can't do this:
    // static int shotsFired = 0;
    // because it's static, it still has to be defined in the cpp file.

public:
    Gun(Magazine m);    // This gun object is initialized with a magazine.


    ~Gun();             // This is called a destructor. NOT a deconstructor.
                        // This code is called any time the object is removed from memory.

    void Fire(int numTimes);
    void Reload();
    bool IsLoaded() const;  // Mark that a memeber function doesn't modify the object by putting const at the end the declaration.


    static int ShotsFired();    // Because our static counter is private, we need a function to access the variable externally.
};