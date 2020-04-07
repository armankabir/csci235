template <class ItemType>
class Node{
    private:
        ItemType item;
        Node<ItemType>* nextHospital

    public:

        virtual ItemType getItem();

        virtual Node<ItemType>* getNext();

        virtual void setNext(Node<ItemType>* nextPtr);


};

template <class ItemType>
class covid_19_outbreak {
    private:
        Node<ItemType>* headHospital;
        int hospitalCount;

    public:
 

        //@return returns amount of hospitals in the list
        virtual int hospitalCount() const = 0;

        //@pre checks if bag is empty based on itemCount
        //@return if bag is empty, returns true, else it returns false
        virtual bool isEmpty() const = 0;

        
        //@param hopital takes in the hospital to be added to the linked list
        //@post if successful, the hospital will be added to the end of the linked list
        //@return returns true when successfully adds a hospital, else returns false
       virtual bool addHospital(Node<ItemType>* hospital) = 0;


        //@param position asks the user which hospital they want the item returned
        //@post if successful, will reurn the item at the node of the given position
        virtual  ItemType getPatientsInfected(int position) = 0;

        //@post clears the list
        virtual void clear() = 0

};

int power2(int x, int n){
    if(n == 0) return 1;
    if(n%2 = 0 ){
        return (x, (n/2)*2)
    }

    else return x*power2(x, (n/2)*2);
}