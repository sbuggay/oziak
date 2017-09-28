struct rect_t {
    int x;
    int y;
    int width;
    int height;
};

int collide(rect_t a, rect_t b) {
    return (a.x < b.x + b.width &&
        a.x + a.width > b.x &&
        a.y < a.y + b.height &&
        a.height + a.y > b.y);
}