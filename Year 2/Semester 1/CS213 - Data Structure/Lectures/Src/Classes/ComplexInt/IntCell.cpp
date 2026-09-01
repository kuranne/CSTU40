class IntCell {
    private:
        int *storeValue;
    public:
        // Constructor
        IntCell(int InitialValue = 0) {
            storeValue = new int (InitialValue);
        }
        
        // Destructor
        // This will call when out of scope or something else I don't sure.
        ~IntCell() {
            delete storeValue;
        }
        
        int read() const {
            return *storeValue;
        }
        
        void write(int x) {
            storeValue = new int (x);
        }
};