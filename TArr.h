//
// Created by Kacper Kuchta on 5/11/23.
//

#ifndef CPP_TASK_18_TARR_H
#define CPP_TASK_18_TARR_H

#include <iostream>
#include <algorithm>

class TArr {
private:
    struct InnerArray {
        std::size_t len{0};
        std::size_t ref{0};
        int *buf{nullptr};

        explicit InnerArray(std::size_t length) : len(length), ref(1), buf(new int[length]) {}

        InnerArray(const InnerArray& other) : len(other.len), ref(1), buf(new int[other.len]) {
            std::copy(other.buf, other.buf + len, buf);
        }

        ~InnerArray() {
            delete[] buf;
        }
    } *ptr{nullptr};

public:
    TArr() {}

    TArr(const TArr& other) : ptr(other.ptr) {
        if (ptr) {
            ptr->ref++;
        }
    }

    TArr(TArr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    TArr& operator=(const TArr& other) {
        if (this != &other) {
            if (ptr && --ptr->ref == 0) {
                delete ptr;
            }
            ptr = other.ptr;
            if (ptr) {
                ptr->ref++;
            }
        }
        return *this;
    }

    TArr& operator=(TArr&& other) noexcept {
        if (this != &other) {
            if (ptr && --ptr->ref == 0) {
                delete ptr;
            }
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~TArr() {
        if (ptr && --ptr->ref == 0) {
            delete ptr;
        }
    }

    std::size_t getRefCount() const {
        if (ptr) {
            return ptr->ref;
        }
        return 0;
    }

    void modifyData() {
        if (ptr) {
            if (ptr->ref > 1) {
                InnerArray* newPtr = new InnerArray(*ptr);
                if (--ptr->ref == 0) {
                    delete ptr;
                }
                ptr = newPtr;
            }

            for (std::size_t i = 0; i < ptr->len; i++) {
                ptr->buf[i] += 1;
            }
        }
    }
};

#endif //CPP_TASK_18_TARR_H
