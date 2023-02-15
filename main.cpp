#include "test_multiThreading.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test_multiThreading w;
	w.show();
	return a.exec();
}
