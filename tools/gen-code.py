from mako.template import Template
import sys, os, argparse
from utils import get_config_by_key
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))) + '/build')

def build_output_path(args):
    # args.output
    # <rule>
    # xxx => all lower
    # Xxx => first character upper only
    # XXX => all upper
    # XxX => original string
    # output file path
    replacement = args.key
    if args.key != "":
        args.output = args.output.replace('xxx', replacement.lower())
        args.output = args.output.replace('Xxx', replacement[0].upper() + replacement[1:])
        args.output = args.output.replace('XXX', replacement.upper())
        args.output = args.output.replace('XxX', replacement)

    # output file name
    output_file_name = os.path.split(args.input)[1][:-5] # remove path & '.stcI'
    if args.key != "":
        output_file_name = output_file_name.replace('xxx', args.key.lower())
        output_file_name = output_file_name.replace('Xxx', args.key[0].upper() + args.key[1:])
        output_file_name = output_file_name.replace('XXX', args.key.upper())
        output_file_name = output_file_name.replace('XxX', args.key)
    output_file_name = output_file_name.split('.')[0] # remove extension
    output_file_name = args.prefix + output_file_name + args.postfix + '.' + os.path.split(args.input)[1].split('.')[-2]

    # final output path
    return args.output + output_file_name

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--key', '-k', default="", help="hash key name")
    parser.add_argument('--input', '-i', help="input file path")
    parser.add_argument('--output', '-o', help="output file path")
    parser.add_argument('--prefix', '-p', default="", help="output file prefix")
    parser.add_argument('--postfix', default="", help="output file postfix")
    args = parser.parse_args()

    args.key = args.key.split('.')[0] if args.key != "" else "" # ex) audio.python.data => audio
    #config = get_config_by_key(args.key)
    config = ""

    template = Template(filename=os.path.abspath(args.input), input_encoding='utf-8', output_encoding='utf-8')
    out = build_output_path(args)
    if not os.path.exists(os.path.dirname(out)):
        os.makedirs(os.path.dirname(out))
    with open(out, mode='wb') as f:
        f.write(template.render(key=args.key, config=config))

if __name__ == "__main__":
    main()
