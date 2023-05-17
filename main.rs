use csc411_image::{Read, GrayImage};
//black is 0 and bright as possible is 1
use std::{env, str::EncodeUtf16, ffi::FromVecWithNulError, vec};

fn main() {
    let input = env::args().nth(1); 
    //match sttamnet ====== input.unwrap()==None == None
    assert!(env::args().len() == 2, "A portable graymap is promised but not delivered"); 
    let img = GrayImage::read(input.as_deref()).unwrap();
    let denom: f32 = img.denominator as f32;
    //for pixel in img.pixels.iter() { println! ("pixel: []", ) }
    let brightness: f32;
    // let average = 0;
    let mut temp = 0.0;
    for gray in img.pixels.iter() {
        let value: f32 = gray.value as f32 / denom;
        //divide each pixel by denom

        temp = temp + value;
    }
        //will get average brightness
        brightness = temp  / img.pixels.len() as f32;
        //round to three decimal points

    println!("{:.3}", brightness);
}

