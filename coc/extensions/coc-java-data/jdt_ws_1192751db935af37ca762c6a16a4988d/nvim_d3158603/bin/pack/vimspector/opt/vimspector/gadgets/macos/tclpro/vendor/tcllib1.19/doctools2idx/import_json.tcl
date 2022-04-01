# json.tcl --
#
#	The json import plugin. Bridge between import management and
#	the parsing of json markup.
#
# Copyright (c) 2009 Andreas Kupries <andreas_kupries@sourceforge.net>
#
# See the file "license.terms" for information on usage and redistribution
# of this file, and for a DISCLAIMER OF ALL WARRANTIES.
# 
# RCS: @(#) $Id$

# This package is a plugin for the the doctools::idx v2 system.  It
# takes text in json format and produces the list serialization of a
# keyword index.

# ### ### ### ######### ######### #########
## Requisites

# @sak notprovided dict
# @mdgen NODEP: doctools::idx::import::plugin

package require Tcl 8.4
package require doctools::idx::import::plugin ; # The presence of this
						# pseudo package
						# indicates execution
						# of this code inside
						# of an interpreter
						# which was properly
						# initialized for use
						# by import plugins.
package require doctools::idx::structure      ; # Verification of the json
					        # parse result as a
					        # proper index
					        # serialization.

if {[package vcompare [package present Tcl] 8.5] < 0} {
    if {[catch {
	package require dict
    }]} {
	# Create a pure Tcl implementation of the dict methods
	# required by json, and fake the presence of the dict package.
	proc dict {cmd args} { return [uplevel 1 [linsert $args 0 dict/$cmd]] }
	proc dict/create {} { return {} }
	proc dict/set {var key val} {
	    upvar 1 $var a
	    array set x $a
	    set x($key) $val
	    set a [array get x]
	    return
	}
	package provide dict 1
    }
}

package require json ; # The actual json parser used by the plugin.
# Requires 8.5, or 8.4+dict.

# ### ### ### ######### ######### #########

# ### ### ### ######### ######### #########
## API :: Convert text to canonical index serialization.

proc import {text configuration} {
    # Note: We cannot fail here on duplicate keys in the input,
    # especially for keywords and references, as we do for Tcl-based
    # canonical index serializations, because our underlying JSON
    # parser automatically merges them, by taking only the last found
    # definition. I.e. of two or more definitions for a key X the last
    # overwrites all previous occurrences.
    return [doctools::idx::structure canonicalize [json::json2dict $text]]
}

# ### ### ### ######### ######### #########
## Ready

package provide doctools::idx::import::json 0.1
return
