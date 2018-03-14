/* 1.1 Для разрешения коллизий используйте квадратичное пробирование. i-ая проба g(k, i)=g(k, i-1) + i (mod m). m - степень двойки*/




#include <assert.h>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int InitSize = 8;
const int HashParameter = 5;

int Hash(const string& data, int m, int probe)
{
    int hash = 0;
    
    for (size_t i = 0; i < data.length(); ++i) {
        hash = (hash * HashParameter + data[i]) % m;
    }
    return  (hash +probe * (probe + 1) / 2)%m;
}

struct CHashTableNode {
    string Data;
    bool isDeleted;
    CHashTableNode(const string& data): Data(data), isDeleted(false)
    {
    }
};

class CHashTable {
public:
    CHashTable()
    {
        table.assign(InitSize, NULL);
        count = 0;
    }
    
    bool Has(const string& key) const;
    bool Add(const string& key);
    bool Delete(const string& key);
    
private:
    vector<CHashTableNode*> table;
    size_t count;
    
    void Rehash();
};



void CHashTable::Rehash()
{
    vector<CHashTableNode*> old_table = table;
    
    table.assign(table.size() * 2, NULL);
    count = 0;
    
    for (size_t i = 0; i < old_table.size(); ++i) {
        if (old_table[i] != NULL && !old_table[i]->isDeleted) {
            Add(old_table[i]->Data);
            delete old_table[i];
        }
    }
}

bool CHashTable::Delete(const string& key)
{
    int hash;
    
    for (size_t probe = 0; probe < table.size(); ++probe) {
        hash = Hash(key, table.size(), probe);
        
        if (table[hash] != NULL && table[hash]->Data == key && !table[hash]->isDeleted)
            break;
        else if (table[hash] == NULL)
            return false;
    }
    
    if (table[hash] == NULL) {
        return false;
    }
    
    table[hash]->isDeleted = true;
    --count;
    
    return true;
}

bool CHashTable::Has(const string& key) const
{
    for (size_t probe = 0; probe < table.size(); ++probe) {
        int hash = Hash(key, table.size(), probe);
        
        if (table[hash] != NULL && table[hash]->Data == key && !table[hash]->isDeleted)
            return true;
        else if (table[hash] == NULL)
            break;
    }
    
    return false;
}

bool CHashTable::Add(const string& key)
{
    int hash;
    int insertPlace = -1;
    
    for (size_t probe = 0; probe < table.size(); ++probe) {
        hash = Hash(key, table.size(), probe);
        
        if (table[hash] != NULL && table[hash]->Data == key && !table[hash]->isDeleted) {
            return false;
        }
        else if (table[hash] == NULL) {
            if (insertPlace == -1)
                insertPlace = hash;
            break;
        }
        else if (table[hash]->isDeleted) {
            if (insertPlace == -1)
                insertPlace = hash;
        }
    }
    
    if (insertPlace == -1) {
        return false;
    }
    
    if (table[insertPlace] != NULL) {
        delete table[insertPlace];
    }
    
    table[insertPlace] = new CHashTableNode(key);
    ++count;
    
    if (count >= table.size() * 3 / 4) {
        Rehash();
    }
    
    return true;
}

int main()
{
    CHashTable table;
    
    char command = 0;
    std::string value;
    while (cin >> command >> value) {
        bool commandSucceeded = false;
        switch (command) {
            case '+':
                commandSucceeded = table.Add(value);
                break;
            case '-':
                commandSucceeded = table.Delete(value);
                break;
            case '?':
                commandSucceeded = table.Has(value);
                break;
            default:
                assert(false);
        }
        cout << (commandSucceeded ? "OK" : "FAIL") << std::endl;
    }
    return 0;
}




















//return  hash + probe*c1 + c2*probe * probe;

