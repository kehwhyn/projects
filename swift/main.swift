import Foundation

func main () {
    // Determine the file name
    let filename = ".."

    // Read the contents of the specified file
    let contents = try! String(contentsOfFile: filename)

    // Split the file into separate lines
    let lines = contents.split(separator:"\n")

    // Iterate over each line and print the line
    for line in lines {
        print("\(line)")
    }

}