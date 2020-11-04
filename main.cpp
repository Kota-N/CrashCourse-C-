#include <iostream>


// Function ////
// declaration on function goes before main
float sum(float a, float b);
void introduceMe(std::string name, int age=0);




// Pointer ////
void celebrateBDay(int* age);





// Class ////
class Car {
private: // <- make these property not accessible from a class instance
    std::string Color;
    double Price;
protected: // <- can access from class inheriting this class
    std::string Name;
    bool IsBroken;

    // constructor
public:
    Car(std::string name, std::string color, double price) {
        Name = name;
        Color = color;
        Price = price;
        IsBroken = false;
    }

    void getInfo() {
        std::cout << "Name: " << Name << std::endl;
    }
    void crashCar() {
        std::cout << Name << " crashed!" << std::endl;
        IsBroken = true;
    }
    void repairCar() {
        std::cout << Name << " is repaired!" << std::endl;
        IsBroken = false;
    }
    void move() {
        if(IsBroken)
            std::cout << Name << " cannot drive." << std::endl;
        else
            std::cout << Name << " is driving." << std::endl;
    }
};



// Inheritance ////
class FlyingCar :public Car {
public:
    FlyingCar(std::string name, std::string color, double price):Car(name, color, price) {}
    void move() {
        if (IsBroken)
            std::cout << Name << " cannot drive." << std::endl;
        else
            std::cout << Name << " is flying." << std::endl;
    }
};




// Polymorphism ////
class UnderWaterCar :public Car {
public:
UnderWaterCar(std::string name, std::string color, double price):Car(name, color, price){}
void move() {
    if (IsBroken)
        std::cout << Name << " cannot drive." << std::endl;
    else
        std::cout << Name << " is swimming!" << std::endl;
}
};


int main() {
    // Variables ////
    int age = 25;
    const float weight = 65.5;
    double balance = 12345.67;
    char gender = 'm';
    std::string username = "Username";
    std::string colors[10] = {"red", "green", "pink", "blue", "black"}; 
    // std::cout << colors[0];
    // std::cin >> colors[0];
    // std::cout << colors[0];
    colors[1] = "gray";




    // Logic ////
    bool isTodaySunny = false;
    bool isTodayWeekend = true;

    // if (isTodayWeekend && isTodaySunny) {
    //     std::cout << "Go to the park" << std::endl;
    // }
    // else if (isTodayWeekend && !isTodaySunny) {
    //     std::cout << "Take an umbrella" << std::endl;
    // }
    // else {
    //     std::cout << "Go to work" << std::endl;
    // }

    // if (isTodayWeekend) {
    //     if (isTodaySunny)
    //         std::cout << "Go to the park" << std::endl;
    //     else
    //         std::cout << "Go out with an umbrella" << std::endl;
    // }
    // else
    //     std::cout << "Go to work" << std::endl;

    // isTodaySunny ? std::cout << "Go out" : std::cout << "Umbrella";




    // Enumeration and switch ////
    enum EyeColor {Brown, Blue, Green, Gray, Other};

    EyeColor eyeColor = Blue;
    
    switch (99) {
        case Brown:
            std::cout << "80% of people have Brown eyes.";
            break;
        case Blue:
            std::cout << "10% of people have Blue eyes.";
            break;
        case Green:
            std::cout << "2% of people have Green eyes.";
            break;
        case Gray:
            std::cout << "1% of people have Gray eyes.";
            break;
        case Other:
            std::cout << "7% of people have other eye colors.";
            break;
        default:
            std::cout << "What's next?\n" << std::endl;
    }




    // Loop ////
    std::cout << "WHILE:\n";
    int counter = 0;
    while (counter <= 10) {
        std::cout << counter << std::endl;
        counter++;
    }

    std::cout << "DO-WHILE:\n";
    int counter2 = 0;
    do {
        std::cout << counter2 << std::endl;
        counter2++;
    } while (counter2 <= 10);

    std::cout << "FOR LOOP:\n";
    std::string animals[5] = {"cat", "dog", "cow", "goat", "bee"};
    for (int i = 0; i < 5; i++) {
        std::cout << animals[i] << std::endl;
    }




    // Function ////
    std::cout << sum(2.2, 5) << std::endl;
    introduceMe("Me");




    // Pointer ////
    std::cout << age << std::endl;
    celebrateBDay(&age);

    int luckyNumbers[5] = { 1,3,5,7,9 };
    std::cout << luckyNumbers << std::endl; // <- outputtin address
    std::cout << &luckyNumbers[0] << std::endl; // <- address of the first item is the same as the array's

    int* luckyPointer = luckyNumbers;
    std::cout << "Pointing to " << luckyPointer << ", value: " << *luckyPointer << std::endl;
    luckyPointer++;
    std::cout << "Pointing to " << luckyPointer << ", value: " << *luckyPointer << std::endl;




    // Class ////
    Car myCar("Ford", "red", 50000);
    // std::cout << "Name: " << myCar.Name << std::endl;
    myCar.getInfo();
    myCar.move();
    myCar.crashCar();
    myCar.move();
    myCar.repairCar();
    myCar.move();




    // Inheritance ////
     FlyingCar flyingCar("Sky", "black", 500000);
     flyingCar.getInfo();




     // Polymorphism ////
     UnderWaterCar underWaterCar("Water", "blue", 400000);
     myCar.move();
     flyingCar.move();
     underWaterCar.move();

     // base class can point to derived classes
     Car* car1 = &flyingCar;
     Car* car2 = &underWaterCar;
     // invoking methods from address
     car1->getInfo();
     car2->getInfo();

}






// definition of function goes after main
float sum(float a, float b) {
    return a + b;
}
void introduceMe(std::string name, int age) {
    std::cout << "My name is " << name << " and I am " << age << " years old" << std::endl;
}

// Pointer ////
void celebrateBDay(int* age) {
    (*age)++;
    std::cout << "You are now " << *age << " years old!" << std::endl;
}