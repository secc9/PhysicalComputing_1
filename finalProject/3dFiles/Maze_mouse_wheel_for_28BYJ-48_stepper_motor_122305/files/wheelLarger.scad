// Mark Benson

// 23/07/2013

// Creative commons non commercial

// Wheel for maze mouse
// Shaft fitting for 28BYJ-48 geared stepper
// http://www.thingiverse.com/thing:122070

difference()
{
	union()
	{
		//rim
		cylinder(r=60,h=6,$fn=100);

		//boss
		cylinder(r=12/2,h=7,$fn=100);
	}

	union()
	{
		//shaft cutout (shaft with flat)
		translate([0,0,1])
		intersection()
		{
			cylinder(r=5/2,h=8,$fn=40);
			translate([0,0,4]) cube([3,8,10], center=true);
		}

		//rim groove cutout
		translate([0,0,3])
		rotate_extrude(convexity=0, $fn=70)
		translate([60,0,20])
		rotate([0,0,45])
		square([4,4],center=true);

		//holes in the wheel
		for(i = [0:5])
		{
			rotate(i*360/6,[0,0,1])
			translate([39,0,-1])
			cylinder(r=32.5/2,h=10,$fn=40);
		}

	}
}

