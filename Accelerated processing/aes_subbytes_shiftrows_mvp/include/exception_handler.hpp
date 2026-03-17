#ifndef AES_MVP_EXCEPTION_HANDLER_HPP
#define AES_MVP_EXCEPTION_HANDLER_HPP

#include <exception>
#include <iostream>

#include <sycl/sycl.hpp>

namespace fpga_tools {

inline void exception_handler(sycl::exception_list exceptions) {
  for (const std::exception_ptr &e : exceptions) {
    try {
      std::rethrow_exception(e);
    } catch (const sycl::exception &ex) {
      std::cout << "Caught asynchronous SYCL exception:\n"
                << ex.what() << std::endl;
    }
  }
}

}  // namespace fpga_tools

#endif  // AES_MVP_EXCEPTION_HANDLER_HPP
