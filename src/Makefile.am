# Araxes Library, A C++ library of Lockfree data structures tools.
#
# Copyright (c) 2015 Soroush Rabiei <rabiei@tidm.ir>,
#
# libaraxes is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# See the file COPYING included with this distribution for more
# information.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

AM_CXXFLAGS = -pedantic -Wall -Werror
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

lib_LTLIBRARIES = libaraxes.la

libaraxes_la_SOURCES = \
	shared_mutex.cpp

araxes_includedir = $(includedir)/araxes
araxes_include_HEADERS =  \
	deque.hpp \
	deque.tpp \
	shared_mutex.hpp
