/*
main.cpp
CSPB 1300 Image Processing Application

PLEASE FILL OUT THIS SECTION PRIOR TO SUBMISSION

- Your name:
    Stephen Andrew Hogan

- All project requirements fully met? (YES or NO):
    YES

- If no, please explain what you could not get to work:
    N/A

- Did you do any optional enhancements? If so, please explain:
    -- Added bool safe_name function -- Tests to ensure the user inputs a name that will not conflict with file naming conventions once it is time to write an image.
    -- Safeguarded user menu input choice using an if statement for cin.fail().
    
    
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

//***************************************************************************************************//
//                                DO NOT MODIFY THE SECTION BELOW                                    //
//***************************************************************************************************//

// Pixel structure
struct Pixel
{
    // Red, green, blue color values
    int red;
    int green;
    int blue;
};

/**
 * Gets an integer from a binary stream.
 * Helper function for read_image()
 * @param stream the stream
 * @param offset the offset at which to read the integer
 * @param bytes  the number of bytes to read
 * @return the integer starting at the given offset
 */ 
int get_int(fstream& stream, int offset, int bytes)
{
    stream.seekg(offset);
    int result = 0;
    int base = 1;
    for (int i = 0; i < bytes; i++)
    {   
        result = result + stream.get() * base;
        base = base * 256;
    }
    return result;
}

/**
 * Reads the BMP image specified and returns the resulting image as a vector
 * @param filename BMP image filename
 * @return the image as a vector of vector of Pixels
 */
vector<vector<Pixel>> read_image(string filename)
{
    // Open the binary file
    fstream stream;
    stream.open(filename, ios::in | ios::binary);

    // Get the image properties
    int file_size = get_int(stream, 2, 4);
    int start = get_int(stream, 10, 4);
    int width = get_int(stream, 18, 4);
    int height = get_int(stream, 22, 4);
    int bits_per_pixel = get_int(stream, 28, 2);

    // Scan lines must occupy multiples of four bytes
    int scanline_size = width * (bits_per_pixel / 8);
    int padding = 0;
    if (scanline_size % 4 != 0)
    {
        padding = 4 - scanline_size % 4;
    }

    // Return empty vector if this is not a valid image
    if (file_size != start + (scanline_size + padding) * height)
    {
        return {};
    }

    // Create a vector the size of the input image
    vector<vector<Pixel>> image(height, vector<Pixel> (width));

    int pos = start;
    // For each row, starting from the last row to the first
    // Note: BMP files store pixels from bottom to top
    for (int i = height - 1; i >= 0; i--)
    {
        // For each column
        for (int j = 0; j < width; j++)
        {
            // Go to the pixel position
            stream.seekg(pos);

            // Save the pixel values to the image vector
            // Note: BMP files store pixels in blue, green, red order
            image[i][j].blue = stream.get();
            image[i][j].green = stream.get();
            image[i][j].red = stream.get();

            // We are ignoring the alpha channel if there is one

            // Advance the position to the next pixel
            pos = pos + (bits_per_pixel / 8);
        }

        // Skip the padding at the end of each row
        stream.seekg(padding, ios::cur);
        pos = pos + padding;
    }

    // Close the stream and return the image vector
    stream.close();
    return image;
}

/**
 * Sets a value to the char array starting at the offset using the size
 * specified by the bytes.
 * This is a helper function for write_image()
 * @param arr    Array to set values for
 * @param offset Starting index offset
 * @param bytes  Number of bytes to set
 * @param value  Value to set
 * @return nothing
 */
void set_bytes(unsigned char arr[], int offset, int bytes, int value)
{
    for (int i = 0; i < bytes; i++)
    {
        arr[offset+i] = (unsigned char)(value>>(i*8));
    }
}

/**
 * Write the input image to a BMP file name specified
 * @param filename The BMP file name to save the image to
 * @param image    The input image to save
 * @return True if successful and false otherwise
 */
bool write_image(string filename, const vector<vector<Pixel>>& image)
{
    // Get the image width and height in pixels
    int width_pixels = image[0].size();
    int height_pixels = image.size();

    // Calculate the width in bytes incorporating padding (4 byte alignment)
    int width_bytes = width_pixels * 3;
    int padding_bytes = 0;
    padding_bytes = (4 - width_bytes % 4) % 4;
    width_bytes = width_bytes + padding_bytes;

    // Pixel array size in bytes, including padding
    int array_bytes = width_bytes * height_pixels;

    // Open a file stream for writing to a binary file
    fstream stream;
    stream.open(filename, ios::out | ios::binary);

    // If there was a problem opening the file, return false
    if (!stream.is_open())
    {
        return false;
    }

    // Create the BMP and DIB Headers
    const int BMP_HEADER_SIZE = 14;
    const int DIB_HEADER_SIZE = 40;
    unsigned char bmp_header[BMP_HEADER_SIZE] = {0};
    unsigned char dib_header[DIB_HEADER_SIZE] = {0};

    // BMP Header
    set_bytes(bmp_header,  0, 1, 'B');              // ID field
    set_bytes(bmp_header,  1, 1, 'M');              // ID field
    set_bytes(bmp_header,  2, 4, BMP_HEADER_SIZE+DIB_HEADER_SIZE+array_bytes); // Size of BMP file
    set_bytes(bmp_header,  6, 2, 0);                // Reserved
    set_bytes(bmp_header,  8, 2, 0);                // Reserved
    set_bytes(bmp_header, 10, 4, BMP_HEADER_SIZE+DIB_HEADER_SIZE); // Pixel array offset

    // DIB Header
    set_bytes(dib_header,  0, 4, DIB_HEADER_SIZE);  // DIB header size
    set_bytes(dib_header,  4, 4, width_pixels);     // Width of bitmap in pixels
    set_bytes(dib_header,  8, 4, height_pixels);    // Height of bitmap in pixels
    set_bytes(dib_header, 12, 2, 1);                // Number of color planes
    set_bytes(dib_header, 14, 2, 24);               // Number of bits per pixel
    set_bytes(dib_header, 16, 4, 0);                // Compression method (0=BI_RGB)
    set_bytes(dib_header, 20, 4, array_bytes);      // Size of raw bitmap data (including padding)                     
    set_bytes(dib_header, 24, 4, 2835);             // Print resolution of image (2835 pixels/meter)
    set_bytes(dib_header, 28, 4, 2835);             // Print resolution of image (2835 pixels/meter)
    set_bytes(dib_header, 32, 4, 0);                // Number of colors in palette
    set_bytes(dib_header, 36, 4, 0);                // Number of important colors

    // Write the BMP and DIB Headers to the file
    stream.write((char*)bmp_header, sizeof(bmp_header));
    stream.write((char*)dib_header, sizeof(dib_header));

    // Initialize pixel and padding
    unsigned char pixel[3] = {0};
    unsigned char padding[3] = {0};

    // Pixel Array (Left to right, bottom to top, with padding)
    for (int h = height_pixels - 1; h >= 0; h--)
    {
        for (int w = 0; w < width_pixels; w++)
        {
            // Write the pixel (Blue, Green, Red)
            pixel[0] = image[h][w].blue;
            pixel[1] = image[h][w].green;
            pixel[2] = image[h][w].red;
            stream.write((char*)pixel, 3);
        }
        // Write the padding bytes
        stream.write((char *)padding, padding_bytes);
    }

    // Close the stream and return true
    stream.close();
    return true;
}

//***************************************************************************************************//
//                                DO NOT MODIFY THE SECTION ABOVE                                    //
//***************************************************************************************************//





bool safe_name(string filename)
{
    //Helper function for process UI
    
    
    string bad_chars = "#%&{}\\ /<>*?$!'\":@+`";
    //Implement a failsafe to only accept appropriate file names
        for (int i = 0; i < bad_chars.length(); i++)
        {
            for (int j = 0; j < filename.length(); j++)
            {
                if (filename[j] == bad_chars[i])
                {
                    return false;
                }
            }
        } 
    return true;
            
}




//Process 1: Vignette
vector<vector<Pixel>> process_1(const vector<vector<Pixel>>& image)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    */
    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    //Step 3. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Find the distance to the center
            double distance = sqrt(pow(col - (num_columns/2), 2) + pow(row - (num_rows/2), 2));
            double scaling_factor = (num_rows - distance)/num_rows;
            
            //Access each Red, Green, Blue value of each Pixel
            //Modify pixels using the scaling factor
            new_image[row][col].red *= scaling_factor;
            new_image[row][col].green *= scaling_factor;
            new_image[row][col].blue *= scaling_factor;
        }
    }
    //Step 4. Return the modified vector of vectors of Pixels
    return new_image;
}





//Process 2: Clarendon
vector<vector<Pixel>> process_2(const vector<vector<Pixel>>& image, double scaling_factor)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    @scaling_factor a double between 0-1 that describes the magnitude by which to decrease each color
    */
    
    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    //Step 3. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue value of each Pixel, assign to variable
            int red_value = new_image[row][col].red;
            int green_value = new_image[row][col].green;
            int blue_value = new_image[row][col].blue;
            
            //Average the values
            double average_value = (red_value + green_value + blue_value)/3;
            
            //If cell is light, make it lighter:
            if (average_value >= 170)
            {
                new_image[row][col].red = (255 - (255 - new_image[row][col].red)*scaling_factor);
                new_image[row][col].green = (255 - (255 - new_image[row][col].green)*scaling_factor);
                new_image[row][col].blue = (255 - (255 - new_image[row][col].blue)*scaling_factor);
            }
            
            //If cell is dark, make it darker
            else if (average_value < 90)
            {
                new_image[row][col].red *= scaling_factor;
                new_image[row][col].green *= scaling_factor;
                new_image[row][col].blue *= scaling_factor;
            }
            
            else //keep pixel the same
            {
                new_image[row][col].red = red_value;
                new_image[row][col].green = green_value;
                new_image[row][col].blue = blue_value;
            }
            
        }
    }
    //Step 4. Return the modified vector of vectors of Pixels
    return new_image;
}





//Process 3: Grayscale
vector<vector<Pixel>> process_3(const vector<vector<Pixel>>& image)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    */
    
    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    //Step 3. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue value of each Pixel
            //Assign new variables
            int red_value = new_image[row][col].red;
            int green_value = new_image[row][col].green;
            int blue_value = new_image[row][col].blue;
            
            //Average the values to achieve the gray_value
            double gray_value = (red_value + green_value + blue_value)/3;
            
            //Set all colors of the pixel to the gray_value
            new_image[row][col].red = gray_value;
            new_image[row][col].green = gray_value;
            new_image[row][col].blue = gray_value;
        }
    }
    //Step 4. Return the modified vector of vectors of Pixels
    return new_image;
}





//Process 4: Rotate 90 Degrees
vector<vector<Pixel>> process_4(const vector<vector<Pixel>>& image)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    */

    //Step 1. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = image[0].size();
    
    //Step 2. Define a new vector of vector of pixels using the dimensions of the input image
    //However, switch the height and width
    
    vector<vector<Pixel>> new_image (num_columns, vector<Pixel> (num_rows));
    
    //Step 3. Use nested for loops to iterate over each pixel in the user image
    
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue value of each Pixel *in the original image*
            //Define new RGB values to hold and transfer to the new vector
            int red_value = image[row][col].red;
            int green_value = image[row][col].green;
            int blue_value = image[row][col].blue;
            
            //Simulates rotating the image by filling in the back column and going down 
            new_image[col][(num_rows-1)-row].red = red_value;
            new_image[col][(num_rows-1)-row].green = green_value;
            new_image[col][(num_rows-1)-row].blue = blue_value;
        }
    }
    //Step 4. Return the modified vector of vectors of Pixels
    return new_image;
}






//Process 5: Rotate Multiples of 90 Degrees
vector<vector<Pixel>> process_5(const vector<vector<Pixel>>& image, int multiple)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    @multiple specifies number of rotations, and must be an integer
    */

    int angle = multiple * 90;
    if (angle % 90 != 0) 
    {
        cout << "angle must be a multiple of 90 degrees. Please enter a valid number of rotations." << endl;
        return image;    
    } 
    
    //If multiple is an integer, then we can exploit process 4 continuously to rotate the image
    else if (angle % 360 == 0) 
    {
        return image;
    } 
    else if (angle % 360 == 90) 
    {
        return process_4(image);
    } 
    else if (angle % 360 == 180) 
    {
        return process_4(process_4(image));
    } 
    else 
    {
        return process_4(process_4(process_4(image)));
    }
}



//Process 6: Enlarge
vector<vector<Pixel>> process_6(const vector<vector<Pixel>>& image, int x_scale, int y_scale)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    @x_scale dimension by which to enlarge the height of the image
    @y_scale dimension by which to enlarge the width of the image
    */

    //Step 1. Read in the size of the 2D vector, acquiring the height and width of the image

    //Height
    int num_rows = image.size();
    //Width
    int num_columns = image[0].size();
    
    //Create a new 2D vector the same size as the input 2D vector, but use the scale variables to modify this size.
    vector<vector<Pixel>> new_image(num_rows*y_scale, vector<Pixel> (num_columns*x_scale));
    
    //Step 2. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    
    //Iterate over the enlarged scale
    for (int row = 0; row < num_rows*y_scale; row++)
    {
        for (int col = 0; col < num_columns*x_scale; col++)
        {
            //Access each Red, Green, Blue value of each Pixel
            //Dividing row or col by the scale ensures that we are pulling from previous pixels present in the selected image. This simulates "moving back" to previous cells and repeating this pixel.
            //Adding 0.5 is a precautionary measure to round upward for the right pixel
            int red_value = image[(row/y_scale)+0.5][(col/x_scale)+0.5].red;
            int green_value = image[(row/y_scale)+0.5][(col/x_scale)+0.5].green;
            int blue_value = image[(row/y_scale)+0.5][(col/x_scale)+0.5].blue;
            
            //Set these values as the new pixels in the enlarged image
            new_image[row][col].red = red_value;
            new_image[row][col].green = green_value;
            new_image[row][col].blue = blue_value;
        }
    }
    //Step 3. Return the modified vector of vectors of Pixels
    return new_image;
}






//Process 7: High Contrast
vector<vector<Pixel>> process_7(const vector<vector<Pixel>>& image)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    */

    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue value of each Pixel
            //Assign new variables
            int red_value = new_image[row][col].red;
            int green_value = new_image[row][col].green;
            int blue_value = new_image[row][col].blue;
            
            //Average the values to achieve the gray_value
            double gray_value = (red_value + green_value + blue_value)/3;
            
            //Use conditional to decide between black or white
            //If greater, convert to white
            if (gray_value >= 255/2)
            {
                new_image[row][col].red = 255;
                new_image[row][col].green = 255;
                new_image[row][col].blue = 255;
            }
            
            //If lesser, convert to black
            else
            {
                new_image[row][col].red = 0;
                new_image[row][col].green = 0;
                new_image[row][col].blue = 0;
            }
        }
    }
    //Step 3. Return the modified vector of vectors of Pixels
    return new_image;
}






//Process 8: Lighten
vector<vector<Pixel>> process_8(const vector<vector<Pixel>>& image, double scaling_factor)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    @scaling_factor a double between 0-1 that describes the magnitude by which to decrease each color
    */
    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    //Step 3. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue value of each Pixel
            //Modify each one using the scaling_factor
            new_image[row][col].red = (255 - (255 - new_image[row][col].red)*scaling_factor);
            new_image[row][col].green = (255 - (255 - new_image[row][col].green)*scaling_factor);
            new_image[row][col].blue = (255 - (255 - new_image[row][col].blue)*scaling_factor);
        }
    }
    //Step 3. Return the modified vector of vectors of Pixels
    return new_image;
}





//Process 9: Darken

vector<vector<Pixel>> process_9(const vector<vector<Pixel>>& image, double scaling_factor)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    @scaling_factor a double between 0-1 that describes the magnitude by which to decrease each color
    */
    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    //Step 3. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue value of each Pixel
            //Modify each one using the scaling_factor
            new_image[row][col].red *= scaling_factor;
            new_image[row][col].green *= scaling_factor;
            new_image[row][col].blue *= scaling_factor;
        }
    }
    //Step 3. Return the modified vector of vectors of Pixels
    return new_image;
}





//Process 10: BWRGB
vector<vector<Pixel>> process_10(const vector<vector<Pixel>>& image)
{
    /*
    @image The image being inserted, should be the copy of the user_image
    */
    //Step 1. Create a new 2D vector of vector of Pixels.
    //For this process, we can simply make a copy of the user_image
    vector<vector<Pixel>> new_image = image;
    
    //Step 2. Read in the size of the 2D vector, acquiring the height and width of the image
    //Height is indicated by the num_rows of the image
    int num_rows = new_image.size();
    //Width of the image/num_columns is indicated by the number of entries in a single vector within the vector
    int num_columns = new_image[0].size();
    
    //Step 3. Use nested for loops to iterate over each pixel in the vector of vectors, and update each color value
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_columns; col++)
        {
            //Access each Red, Green, Blue and save their values
            int red_value = new_image[row][col].red;
            int green_value = new_image[row][col].green;
            int blue_value = new_image[row][col].blue;
            //int max_color = max(red_value, green_value, blue_value);
            
            //First check to see if the pixel is saturated
            //Converts pixel to White
            if ((red_value + green_value + blue_value) >= 550)
            {
                new_image[row][col].red = 255;
                new_image[row][col].green = 255;
                new_image[row][col].blue = 255;
            }
            
            //Then check if it is unsaturated
            //Converts pixel to Black
            else if (red_value + green_value + blue_value <= 150)
            {
                new_image[row][col].red = 0;
                new_image[row][col].green = 0;
                new_image[row][col].blue = 0;
            }
            
            //Finally check whether one color is dominant over the others
            //Converts pixel to Red
            else if (max(red_value, green_value) == red_value && max(red_value, blue_value) == red_value)
            {
                new_image[row][col].red = 255;
                new_image[row][col].green = 0;
                new_image[row][col].blue = 0;
            }
            
            //Converts pixel to Green
            else if (max(green_value, red_value) == green_value && max(green_value, blue_value) == green_value)
            {
                new_image[row][col].red = 0;
                new_image[row][col].green = 255;
                new_image[row][col].blue = 0;
            }
            
            //Converts pixel to Blue
            else
            {
                new_image[row][col].red = 0;
                new_image[row][col].green = 0;
                new_image[row][col].blue = 255;
            }
        }
    }
    //Step 3. Return the modified vector of vectors of Pixels
    return new_image;
}



int main()
{
    
    /*
    Initializing variables upon start of the program
    @filename Updated to reflect selected file in process 0
    @user_input simple switch for navigating the UI
    @user_image Initialized to contain the user image input later
    @@user_image_pointer Pointer to user image data
    */
    
    string filename = "NONE SELECTED";
    int user_input = -1;
    vector<vector<Pixel>> user_image;
    vector<vector<Pixel>>* user_image_pointer = &user_image;
    
	while (user_input < 11)
    {
        cout << "\n\nCSPB 1300 Image Processing Application\nby Andrew Hogan\n\n";
        
        cout << "IMAGE PROCESSING MENU\n\n";
        cout << "0) Change image (current: " << filename << ")" << endl;
        cout << "1) Vignette\n";
        cout << "2) Clarendon\n";
        cout << "3) Grayscale\n";
        cout << "4) Rotate 90 degrees\n";
        cout << "5) Rotate multiples of 90 degrees\n";
        cout << "6) Enlarge\n";
        cout << "7) High Contrast\n";
        cout << "8) Lighten\n";
        cout << "9) Darken\n";
        cout << "10) BWRGB\n";
        cout << "11) EXIT\n\n";
        
        cout << "Enter menu selection: ";
        cin >> user_input;
        
        
        
        //If user is silly, we can prevent a crash with an input failsafe. Just assume the user is exiting the program.
        if (cin.fail())
        {
            //Greet the user upon exit
            cout << "\nThank you for using my program!\nClosing...\n\n";

            return 0;
        }
        
        
        //Process 0: Change image
        if (user_input == 0)
        {
            filename = "";
            while(filename == "")
            {
                cout << "\nInput filename located within the same directory: ";
                cin >> filename;
                // Read sample.bmp file and store in 2D vector named image
                if (safe_name(filename) == true)
                {
                    *user_image_pointer = read_image(filename);  
                }
                else
                {
                    cout << "\n\nEnter a valid filename. \n";
                    filename = "NONE SELECTED";                    
                }
                
            }
            user_input = -1;
        }
        
        
        
        
        
        
        //Process 1: Vignette:
        if (user_input == 1)
        {   
            //Process 1: Vignette
            vector<vector<Pixel>> new_image = process_1(*user_image_pointer);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        
        
        //Process 2: Clarendon
        if (user_input == 2)
        {   
            //Prompt for the scaling factor:
            double scaling_factor;
            cout << "Enter a scaling factor between 0 and 1 (e.g. 0.5)";
            cin >> scaling_factor;
            
            //Process 2: Clarendon
            vector<vector<Pixel>> new_image = process_2(*user_image_pointer, scaling_factor);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            
            user_input = -1;
        }
        
        
        
        
        
        
        //Process 3: Grayscale:
        if (user_input == 3)
        {   
            //Process 3: Grayscale
            vector<vector<Pixel>> new_image = process_3(*user_image_pointer);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            
            user_input = -1;
        }
        
        
        
        
        
        
        
        //Process 4: Rotate 90 Degrees:
        if (user_input == 4)
        {   
            //Process 4:
            vector<vector<Pixel>> new_image = process_4(*user_image_pointer);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        
        
        
        //Process 5: Rotate multiples of 90 Degrees:
        if (user_input == 5)
        {   
            
            //Prompt user for multiple:
            int multiple;
            cout << "Enter an integer indicating the number of times to rotate the image: ";
            cin >> multiple;
            
            //Process 5: Rotate multiples of 90 Degrees
            vector<vector<Pixel>> new_image = process_5(*user_image_pointer, multiple);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        
        
        
        //Process 6: Enlarge:
        if (user_input == 6)
        {   
            //Prompt user for scales:
            int x_scale;
            int y_scale;
            cout << "Enter x scale: ";
            cin >> x_scale;
            cout << "\nEnter y scale: ";
            cin >> y_scale;
            
            //Process 6: Enlarge
            vector<vector<Pixel>> new_image = process_6(*user_image_pointer, x_scale, y_scale);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        
        //Process 7: High Contrast:
        if (user_input == 7)
        {   
            //Process 7: High Contrast
            vector<vector<Pixel>> new_image = process_7(*user_image_pointer);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        
        
        //Process 8: Lighten:
        if (user_input == 8)
        {
            //Prompt for the scaling factor:
            double scaling_factor;
            cout << "Enter a scaling factor between 0 and 1 (e.g. 0.5)";
            cin >> scaling_factor;
            
            //Process 8: Lighten
            vector<vector<Pixel>> new_image = process_8(*user_image_pointer, scaling_factor);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        
        
        //Process 9: Darken:
        if (user_input == 9)
        {
            //Prompt for the scaling factor:
            double scaling_factor;
            cout << "Enter a scaling factor between 0 and 1 (e.g. 0.5)";
            cin >> scaling_factor;
            
            //Process 9: Darken
            vector<vector<Pixel>> new_image = process_9(*user_image_pointer, scaling_factor);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
        
        
        
        
        //Process 10: BWRGB:
        if (user_input == 10)
        {
            //Process 10:
            vector<vector<Pixel>> new_image = process_10(*user_image_pointer);
            
            //Prompt user to save new image
            string new_filename;
            cout << "\nWARNING: Inputting a filename that already exists within the directory\nwill overwrite the file!\n";
            cout << "Input new filename (without any extensions): ";
            cin >> new_filename;
            new_filename += ".bmp";
            
            //Determine whether filename is valid
            if (safe_name(new_filename) == true)
            {
            bool success = write_image(new_filename, new_image);  // Write 2D vector named new_image to file named in new_filename
            }
            else
            {
                cout << "\n\nEnter a valid filename. \n";
            }
            user_input = -1;
        }
          
    }
    
    //Greet the user upon exit
    cout << "\nThank you for using my program!\nClosing...\n\n";

    return 0;
}