#include <iostream>
#include <thread>
#include <Windows.h>
int PapersDone = 0;
static bool Done = false;
void Work() {
	using namespace std::literals::chrono_literals;
	do {
		system("cls");
		std::cout << "I have done " << PapersDone << " papers.";
		PapersDone++;
		Beep(500, 100);
		std::this_thread::sleep_for(.9s);
	} while (!Done);
	system("cls");
}
void Jingle() {
	Beep(350, 120);
	Beep(1250, 90);
}
int main() {
	std::thread Worker(Work);
	std::cin.get();
	Done = true;
	Worker.join();
	std::cout << "Welp im dunhier.\n";
	std::cout << "At least I done " << PapersDone << " papers.";
	Jingle();
	return 0;
}