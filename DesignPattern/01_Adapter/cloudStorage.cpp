#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <random>

using namespace std;

class CloudStorage{
public:
    virtual bool uploadContents(const string& content) = 0;
    virtual int getFreeSpace() = 0;
    virtual ~CloudStorage() = default;
};

class CloudDrive : public CloudStorage{
public:
    bool uploadContents(const string& content) override{
        cout << "Uploading " << content.length() << " bytes to CloudDrive: " << endl;

        return true;
    }

    int getFreeSpace() override{
        // Implement the logic for getting the free space on CloudDrive here.
        // const int size = arc4random_uniform(20); //iOS and macOS only
        static random_device rd;
        static mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, 19);

        int size = dist(mt);
        cout << "Available CloudDrive storage: " << size << "GB" << endl;
        return size;
    }
};

class FastShare : public CloudStorage{
public:
    bool uploadContents(const string& content) override{
        cout << "Uploading " << content.length() << " bytes to FastShare: " << endl;
        return true;
    }

    int getFreeSpace() override{
        // const int size = arc4random_uniform(10);
        static random_device rd;
        static mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, 9);

        int size = dist(mt);
        cout << "Available FastShare storage: " << size << "GB" << endl;
        return size;
    }
};

// 3rd party service
class VirtualDrive{
public:
    bool uploadData(const string& data, const int uniqueID){
        cout << "Uploading to VirtualDrive: \"" << data << "\" ID: " << uniqueID << endl;
        return true;
    }
    int usedSpace(){
        static random_device rd;
        static mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, 9);

        return dist(mt);
        // return arc4random_uniform(10);
    }
    const int totalSpace = 15;
};

class VirtualDriveAdapter: public CloudStorage, private VirtualDrive{
public:

    virtual bool uploadContents(const string& content) override{
        int uniqueID = generateUID();
        cout << "VirtualDriverAdapter::uploadContents() -> Calling VirtualDrive::uploadData()" << endl;
        return uploadData(content, uniqueID);
    }

    virtual int getFreeSpace() override{
        cout << "VirtualDriveAdapter::getFreeSpace() -> Calling VirtualDrive::getAvailableStorage()" << endl;
        const int available = totalSpace - usedSpace();
        cout << "Available VirtualDrive storage: " << available << " GB" << endl;
        return available;
    }

private:
    int generateUID(){
        const time_t result = time(nullptr);
        return result;
    }

};

int main(){
    // Create an array of pointers to CloudStorage objects.
    const unique_ptr<CloudStorage> cloudServices[]{
        make_unique<CloudDrive>(),
        make_unique<FastShare>(),
        make_unique<VirtualDriveAdapter>()
    };

    // Iterate through the array and invoke the uploadContents and getFreeSpace
    // methods on each object.
    const string content = "Beam me up, Scotty!";
    for (const auto &service : cloudServices){        
        service->uploadContents(content);
        service->getFreeSpace();
        cout << endl;
    }

    return 0;
}