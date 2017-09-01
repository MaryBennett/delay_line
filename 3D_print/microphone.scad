// d = 9.5mm, h = 0.45cm --> microphone
// d = 11cm --> tube
// assuming 1cm = 10
expa = 1;


// microphone holder
difference () {
    cylinder(h = 8, d = (14 + 2*expa), center = false);
    translate ([0,0,-1])
        cylinder(h = 6, d = (12 + 2*expa), center = false, $fn = 180); //h = 2*height
    
    translate ([-4,0,1])
    {
        cube([8,4,15], center = false);
    }
}

difference () {
    union () {
        translate ([0,0,8]) {
            rotate ([180,0,90]) {
            // bridge 1
                union () {
                    rotate ([0,0,90]) {
                        difference () {  // bridge
                            translate ([0,0,0])
                                cylinder (h = 3,d = (111 + 2*expa), center = false);
                            translate ([5,-57,-2])
                                cube (115, center = false);
                            translate ([-120,-57,-2])
                                cube (115, center = false);
                        }
                    }
                }

            // connecter
                difference () {
                    cylinder (h = 10,d = 120, center = false);
                    
                    translate ([-65,5,-10])
                        cube ([130,110,100], center = false);
                    translate ([-65,-115,-10])
                        cube ([130,110,100], center = false);
                    
                    translate ([0,0,-10])
                        cylinder (h = 100, d = (110.5 + 2*expa), center = false);
                }
            }
        }
        translate ([0,0,8]) {
            rotate ([180,0,0]) {
            // bridge 2
                union () {
                    rotate ([0,0,90]) {
                        difference () {
                            translate ([0,0,0])
                                cylinder (h = 3,d = (111 + 2*expa), center = false);
                            translate ([5,-57,-2])
                                cube (115, center = false);
                            translate ([-120,-57,-2])
                                cube (115, center = false);
                        }
                    }
                }

            // connecter
                difference () {
                    cylinder (h = 10,d = 120, center = false);
                    
                    translate ([-65,5,-10])
                        cube ([130,110,100], center = false);
                    translate ([-65,-115,-10])
                        cube ([130,110,100], center = false);
                    
                    translate ([0,0,-10])
                        cylinder (h = 100, d = (110.5 + 2*expa), center = false);
                }
            }
        }
    }
    translate([0,0,-20])
          cylinder(h = 111, d = (13 + 2*expa), center = false);  // holder
}

// hoops
translate ([0,60,6]) {
    rotate ([0,0,0]) {
        difference() {
            cylinder(h = 2, r = 5, center = false);
            translate ([0,0,-1])
                cylinder(h = 4, r = 4, center = false);
        }
    }
}
translate ([0,-60,6]) {
    rotate ([0,0,0]) {
        difference() {
            cylinder(h = 2, r = 5, center = false);
            translate ([0,0,-1])
                cylinder(h = 4, r = 4, center = false);
        }
    }
}