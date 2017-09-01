// d = 11.7mm h = 7.1mm l = (13.6-11.7)mm x 0.58cm x 0.58cm (between pins = 6.8mm, 2.5mm)
// tube: 11cm
// add 1 for expansion
expa = 1;
// 1mm = 1

// holder
union (){
    difference () {
        union () {
            translate([0,0,-2])
                cylinder(h = 10, d = (17 + 2*expa), center = false);
            translate([5,-5,-2])
                cube([4,(8 + 2*expa),10], center = false);
        }
        
        union () {
            cylinder(h = 9, d = (14 + 2*expa), center = false, $fn = 180);
            translate([5,-4,2])
                cube([5,(6 + 2*expa),7], center = false);
        }
        
        translate ([3.5,0,-5])
            cylinder(h = 15, d = 3, center = true);
        translate ([-3.5,0,-5])
            cylinder(h = 15, d = 3, center = true);
    }
}

difference () {
    union () {
        translate ([0,0,3]) {
            rotate ([90,180,90]) {
            // bridge
                union () {
                    rotate ([0,0,90]) {
                        difference () {  // bridge
                            translate ([0,0,-5])
                                cylinder (h = 8, d = (111 + 2*expa), center = false);
                            translate ([5,-57,-6])
                                cube ((112 + 2*expa), center = false);
                            translate ([-117,-57,-6])
                                cube ((112 + 2*expa), center = false);
                        }
                    }
                }

            // connecter
                difference () {
                    translate ([0,0,-5]) {
                        cylinder (h = 25,d = (120 + 2*expa), center = false);}
                        
                        translate ([-65,5,-10]){
                            cube ([130,110,100], center = false);}
                        translate ([-65,-115,-10]){
                            cube ([130,110,100], center = false);}
                        
                        translate ([0,0,-10]){
                            cylinder (h = 100,d = (110.5 + 2*expa), center = false);}
                    
                }
            }
        }
    }
    translate([0,0,-20])
          cylinder(h = 111, d = (15 + 2*expa), center = false);  // holder
}

// hoops
difference () {
    union () {
        translate ([5,60,-2]) {
            rotate ([0,0,0]) {
                difference() {
                    cylinder(h = 2, r = 5, center = false);
                    translate ([0,0,-1])
                        cylinder(h = 4, r = 4, center = false);
                }
            }
        }
        translate ([5,-60,-2]) {
            rotate ([0,0,0]) {
                difference() {
                    cylinder(h = 2, r = 5, center = false);
                    translate ([0,0,-1])
                        cylinder(h = 4, r = 4, center = false);
                }
            }
        }
    }
    translate([0,-56,-10])
        cube(112,center = false);
}