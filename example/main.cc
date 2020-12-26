#include <iostream>

#include "TfLiteInterpreter.h"

//convert cat.bmp -resize 224x224! cat.rgb


int main(int argc, char**argv)
{
    TfLiteInterpreter interpreter;

    if(!interpreter.Create())
    {
        return -1;
    }
    if(!interpreter.LoadImage("/home/dev/oosman/repos/edgetpu-minimal/models/cat.rgb"))
    {
        return -1;
    }

    auto res = interpreter.Invoke();
    std::cout << "Inferenced class \"" << res.class_
              << "\" in "
              << res.milliseconds_
              << " milliseconds"
              << "\n";

    return 0;
}
