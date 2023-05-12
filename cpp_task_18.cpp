#include <iostream>
#include "TArr.h"

int main() {
    TArr arr1;
    std::cout << "arr1 Ref Count: " << arr1.getRefCount() << std::endl;

    TArr arr2 = arr1;
    std::cout << "arr1 Ref Count: " << arr1.getRefCount() << std::endl;
    std::cout << "arr2 Ref Count: " << arr2.getRefCount() << std::endl;

    TArr arr3(std::move(arr1));
    std::cout << "arr1 Ref Count: " << arr1.getRefCount() << std::endl;
    std::cout << "arr3 Ref Count: " << arr3.getRefCount() << std::endl;

    TArr arr4;
    arr4 = arr3;
    std::cout << "arr3 Ref Count: " << arr3.getRefCount() << std::endl;
    std::cout << "arr4 Ref Count: " << arr4.getRefCount() << std::endl;

    TArr arr5;
    arr5 = std::move(arr3);
    std::cout << "arr3 Ref Count: " << arr3.getRefCount() << std::endl;
    std::cout << "arr5 Ref Count: " << arr5.getRefCount() << std::endl;

    std::cout << std::endl;

    std::cout << "Modifying arr2" << std::endl;
    arr2.modifyData();
    std::cout << "arr1 Ref Count: " << arr1.getRefCount() << std::endl;
    std::cout << "arr2 Ref Count: " << arr2.getRefCount() << std::endl;
    std::cout << "arr3 Ref Count: " << arr3.getRefCount() << std::endl;
    std::cout << "arr4 Ref Count: " << arr4.getRefCount() << std::endl;
    std::cout << "arr5 Ref Count: " << arr5.getRefCount() << std::endl;

    std::cout << std::endl;

    std::cout << "Modifying arr4" << std::endl;
    arr4.modifyData();
    std::cout << "arr1 Ref Count: " << arr1.getRefCount() << std::endl;
    std::cout << "arr2 Ref Count: " << arr2.getRefCount() << std::endl;
    std::cout << "arr3 Ref Count: " << arr3.getRefCount() << std::endl;
    std::cout << "arr4 Ref Count: " << arr4.getRefCount() << std::endl;
    std::cout << "arr5 Ref Count: " << arr5.getRefCount() << std::endl;
}
