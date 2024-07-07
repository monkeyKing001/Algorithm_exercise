#include <iostream>

void recursiveFunction(int count) {
    int array[100]; // 배열을 추가하여 스택 사용량 증가
    std::cout << "Depth: " << count << std::endl;
    recursiveFunction(count + 1);
}

int main() {
    recursiveFunction(1);
    return 0;
}
