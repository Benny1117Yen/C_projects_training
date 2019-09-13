typedef struct {
	int x;
	int y;
}point;

//point is a struct included in circle.
typedef struct {
	float radius;
	point center;
}circle;

circle c = {4.5, {1, 3}};
pirntf("%3.1f %d, %d", c.radius, c.center.x, c.center.y);
