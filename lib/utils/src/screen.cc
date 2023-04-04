#include "screen.hh"



Screen::Screen()
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    w_ = size.ws_col;
    h_ = size.ws_row;
    ratio_ = (double)w_ / 2 / (double)h_;
    buf_ = std::unique_ptr<char[]>(new char[w_ * h_ + 1]);
    buf_[w_ * h_ ] = 0;
    clear();
}

int Screen::get_w()
{
    return w_;
}

int Screen::get_h()
{
    return h_;
}

double Screen::get_ratio()
{
    return ratio_;
}

bool Screen::put_pixel(int x, int y, char ascii)
{
    if (x < 0 || y < 0 || x >= w_ || y >= h_)
        return false;
    y = h_ - y - 1;
    int pos = w_ * y + x;
    
    buf_[pos] = ascii;
    return true;
}

char Screen::get_pixel(int x, int y)
{
    if (x < 0 || y < 0 || x >= w_ || y >= h_)
        return 0;

    y = h_ - y - 1;
    int pos = w_ * y + x;

    return buf_[pos];
}

void Screen::clear()
{
    for (int i = 0; i < w_ * h_; i++)
    {
        buf_[i] = ' ';
    }
}

void Screen::display()
{
    frame_count++;
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    write(STDOUT_FILENO, buf_.get(), w_ * h_);
    fflush(stdout);
}

long unsigned Screen::frame_count = 0;