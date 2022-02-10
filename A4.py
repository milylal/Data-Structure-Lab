class Set:
    def __init__(self, data=None):
        self.data = {}
        if data != None: 
            if len(data) != len(set(data)):
                data = set(data)
            for d in data:
                self.data[d] = d
    def insert(self, i):
        if i in self.data.keys():
            return 'Already in set'
        self.data[i] = i
    def remove(self, i):
        if i not in self.data.keys():
            return 'Not in set'
        self.data.pop(i)
    def size(self):
        return len(self.data.keys())
    def contains(self, i):
        if i in self.data.keys():
            return True
        return False
    def union(self, otherSet):
        setData = list(set(self.data.keys()) | set(otherSet.data.keys()))
        unionSet = Set(setData)
        return unionSet
    def intersection(self, otherSet):
        setData = list(set(self.data.keys()) & set(otherSet.data.keys()))
        intersectionSet = Set(setData)
        return intersectionSet
    def difference(self, otherSet):
        setData = list(set(self.data.keys()) ^ set(otherSet.data.keys()))
        differenceSet = Set(setData)
        return differenceSet
    def subset(self, otherSet):
        if set(self.data.keys()) < set(otherSet.data.keys()):
            return True
        return False
    def __repr__(self):
      return '['+', '.join(str(x) for x in self.data.keys())+']'
def main():
    set1 = Set([])
    set2 = Set([])
    n1 = int(input("Enter the number of elements in set1: "))
    for i in range(n1):
        data_name = input("Enter the elements : ")
        #insert 
        set1.insert(data_name)
    n2 = int(input("Enter the number of elements in set2: "))
    for i in range(n2):
        data_name = input("Enter the elements : ")
        #insert 
        set2.insert(data_name)
    #users choice
    while(True):
        choice = int(input("Enter 1:Union 2: Intersection 3: size 4.subset 5.difference "))
        if (choice==1):
            print("Set :",set1.union(set2))
        elif (choice==2):
            print("Set :",set1.intersection(set2))
        elif (choice==3):
            print("Size of set 1 :",set1.size())
            print("Size of set 2 :",set2.size())
        elif (choice==4):
            print("Subset :",set1.subset(set2))
        elif (choice==5):
            print("Set :",print(set1.difference(set2)))
        else:
            print("Invalid Choice")
        c=input("Do you want to continue:Y/N")
        if(c=='N'):
            break
if __name__ == "__main__":
    main()
