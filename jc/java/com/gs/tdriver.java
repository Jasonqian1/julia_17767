/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.gs;

/**
 *
 * @author jqian
 */
public class tdriver {

    public native String Call_julia(String v1, String v2);
    public String callcpp(String v1, String v2) {
        return Call_julia(v1,v2);
    }
    static {
        //System.loadLibrary("cjulia");
        System.load("/home/jqian2/Julia/jc/cpp/libcjulia.so");
    }
}
