//Disk.h
//class Disk

#ifndef _DISK_H_
#define _DISK_H_

class Disk 
{
public:
  static Disk* Instance();
	
protected:
  Disk();

private:
  static Disk *instance;

};

#endif
