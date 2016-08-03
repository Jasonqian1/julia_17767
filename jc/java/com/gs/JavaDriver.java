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
public class JavaDriver {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //
       for(int i=0; i<40;i++){
        tdriver obj = new tdriver();
        System.out.println(obj.Call_julia("2", "1.2"));
        try{
          Thread.sleep(50);
        }catch(InterruptedException e){
        }
       }
    }
    
}
