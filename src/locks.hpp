#ifndef ARAXES_LOCKS_HPP_
#define ARAXES_LOCKS_HPP_

#if __cplusplus >= 201402L
#include <shared_mutex>
typedef std::shared_mutex shared_mutex_t;
typedef typename std::shared_lock<std::shared_mutex> shared_lock_t;
typedef typename std::unique_lock<std::shared_mutex> exclusive_lock_t;

#else
#include "shared_mutex.hpp"
typedef araxes::shared_mutex shared_mutex_t;
typedef typename araxes::shared_lock<araxes::shared_mutex> shared_lock_t;
typedef typename std::unique_lock<araxes::shared_mutex> exclusive_lock_t;
#endif

#endif
