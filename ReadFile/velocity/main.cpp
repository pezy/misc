#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <iostream>

struct velocity
{
	double x = 0.0;
	double y = 0.0;
	QMap<int, int> map;
};

void ReadXY(const QString line, velocity& v)
{
	QStringList xy = line.split(" ", QString::SkipEmptyParts);

	v.x = xy.at(2).toDouble();
	v.y = xy.at(3).toDouble();
}

void ReadValue(const QString line, velocity& v)
{
	QStringList values = line.split(" ", QString::SkipEmptyParts);

	int flag = values.at(2).toInt();
	int offset = flag ? 1 : 3;

	for (int i = 0; i != 5; ++i)
	{
		int key = values.at(2 * i + offset).toInt();
		int value = values.at(2 * i + offset + 1).toInt();

		v.map.insert(key, value);
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	// Read
	QFile file("velocity.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return -1;

	std::vector<velocity> vec;
	velocity v;

	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		if (line.left(4) == "SPNT")
		{
			if (!(v.x == 0.0 && v.y == 0.0 && v.map.isEmpty()))
				vec.push_back(v);

			ReadXY(line, v);
		}
		else if (line.left(4) == "VELF")
		{
			ReadValue(line, v);
		}
	}

	file.close();

	// Output
	QFile out("result.txt");
	if (!out.open(QIODevice::WriteOnly | QIODevice::Text))
		return -1;

	QTextStream outStream(&out);
	for (const auto& v : vec)
	{
		for (auto iter = v.map.cbegin(); iter != v.map.cend(); ++iter)
		{
			outStream << QString("%1 %2 %3 %4\n").arg(v.x, 6).arg(v.y, 7, 'f', 0).arg(iter.key()).arg(iter.value());
		}
	}

	std::cout << "finished!" << std::endl;

	return a.exec();
}
