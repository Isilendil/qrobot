//Disk.cpp

Disk *Disk::instance = 0;

Disk::Disk()
{
}

Disk* Disk::Instance()
{
	if (instance == 0)
	{
		instance = new Disk;
	}
	return instance;
}

