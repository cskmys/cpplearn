//
// Created by csk on 18/06/2022.
//

#ifndef STATUS_H
#define STATUS_H

enum Status{ // unscoped "enum"
    Pending, // automatically sets it to 0
    Approved, // increments value from previous one
    Cancelled // no comma required here
}; // don't forget semicolon at the end

/*
enum AnotherStatus{
    Pending // throws compilation error
    // "Pending" is already used in another (unscoped) "enum"
};
*/

enum class FileError { // scoped "enum"
    notfound = 1, // you can specify which value to start from if needed
    ok
};

enum class NetworkError {
    notfound, // no compilation error as this is a scoped "enum"
    disconnected,
    ok
};

#endif //STATUS_H
