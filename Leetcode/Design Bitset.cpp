//TLE

class Bitset {
public:
    vector<int>*v;
    int Ocount = 0, Osize = 0;
    Bitset(int size) {
        v = new vector<int>(size);
        for (int i = 0; i < size; i++) {
            v->at(i) = 0;
        }
        Osize = size;
    }

    void fix(int idx) {
        v->at(idx) = 1;
        Ocount++;
    }

    void unfix(int idx) {
        if (v->at(idx) == 1) {
            Ocount--;
        }
        v->at(idx) = 0;
    }

    void flip() {
        for (int i = 0; i < v->size(); i++) {
            if (v->at(i) == 0) {
                v->at(i) = 1;
                Ocount++;
            }
            else {
                v->at(i) = 0;
                Ocount--;
            }
        }
    }

    bool all() {
        if (Ocount == Osize) {
            return true;
        }
        return false;


    }

    bool one() {
        if (Ocount) {
            return true;
        }
        return false;
    }

    int count() {
        return Ocount;
    }

    string toString() {
        string ans;
        for (int i = 0; i < v->size(); i++) {
            ans.push_back(v->at(i) + '0');
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */