#include <iostream>

#include <vector>

size_t findVolume(std::vector<int> histogram)
{
    size_t left = 0;
    size_t right = histogram.size()-1;

    size_t curArea = 0;

    int curMin = 0;

    while(left < right)
    {
        if(histogram[left] > histogram[right])
        {
            if(histogram[right] <= curMin) {

                curArea -= histogram[right];

            } else if(histogram[right] > curMin) {

                curArea -= curMin;
                curArea += (histogram[right]-curMin)*(right-left-1);
            }

            if(curMin < histogram[right]) curMin = histogram[right];

            --right;

        } else {

            if(histogram[left] <= curMin)
            {
                curArea -= histogram[left];

            } else if(histogram[left] > curMin) {

                curArea -= curMin;
                curArea += (histogram[left]-curMin)*(right-left-1);
            }

            if(curMin < histogram[left]) curMin = histogram[left];

            ++left;
        }
    }
    return curArea;
}

int main()
{
    int res = findVolume({0, 0, 4, 1000, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0});
    std::cout << "res = " << res << '\n';
    return 0;
}
