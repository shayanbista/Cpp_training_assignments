    
    public:
        int *refCount;

        SharedPointer<T>(T* p=nullptr):m_ptr(p), refCount(new int(1)){
                m_ptr=p;
                if(m_ptr){ 
                refCount=new int(1);
                }
                cout<<"ref_count: "<<*refCount<<"\n";
        }


        SharedPointer& operator=(SharedPointer<T> &other){
            if(this ==&other) return *this;
            cout<<"i am called"<<"\n";
            (*refCount)++;
            cout<<"reference count: "<<*refCount<<"\n";
            return *this;
        }