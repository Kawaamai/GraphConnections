/*
 * Filename:  graphconnections.cpp
 * Author:    Alan Mai
 * Date:      2016-29-06
 *
 * Description: A simple program that can perfrom different graph related algorithms on a given 
 *              graph dataset in GML format.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tclap/CmdLine.h>


int main (int argc, char * argv[]) {

  std::string filename;
  bool undirected = false;

  /* ---------- ARG Parsing (TCLAP) ---------- */
  
  try {
    
    // Define the command line object.
    TCLAP::CmdLine cmd("Graph algorithm progrm", ' ', "0.1");

    TCLAP::ValueArg<std::string> filenameArg("f","filename","File to read",true,"homer","string");
    cmd.add(filenameArg);

    TCLAP::SwitchArg undirectedSwitch("u","undirected","Force undirected edges",false);
    cmd.add(undirectedSwitch);

    cmd.parse(argc, argv);

    filename = filenameArg.getValue();
    undirected = undirectedSwitch.getValue();

  
  } catch (TCLAP::ArgException &e) {  // catch any exceptions
    std::cerr << "err: " << e.error() << " for arg " << e.argId() << std::endl;
    return -1;
  }

  if (undirected) {
    std::cout << "undirected forced" << std::endl;
  } else {
    std::cout << "edges maintained" << std::endl;
  }

  std::cout << filename << std::endl;

  return 1;
}
